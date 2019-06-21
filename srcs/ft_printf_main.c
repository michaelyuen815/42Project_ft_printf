/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:43:37 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/11 18:43:39 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_pfmain_var_del(t_var **var)
{
	if (!*var)
		return ;
	free((*var)->len);
	free((*var)->flag);
	free((*var)->input);
	free(*var);
	*var = NULL;
}

t_var	*ft_pfmain_var_init(t_var **var, const char **str, va_list lst_arg)
{
	if (!*var)
	{
		*var = (t_var*)malloc(sizeof(t_var));
		(*var)->flag = (t_flag*)malloc(sizeof(t_flag));
		(*var)->len = (t_len*)malloc(sizeof(t_len));
		(*var)->input = (t_input*)malloc(sizeof(t_input));
	}
	(*var)->flag = ft_pfflag_init(*var, str);
	(*var)->i_width = ft_pfwidpre_init(*var, str, 0, lst_arg);
	(*var)->i_prec = **str == '.' ? \
			ft_pfwidpre_init(*var, str, 1, lst_arg) : -1;
	(*var)->len = ft_pflen_init(*var, str);
	(*var)->c_spec = ft_strchr(SPEC, **str) ? **str : 0;
	*str += ((*var)->c_spec ? 1 : 0);
	ft_pflen_ctrl(*var);
	ft_pfvar_init(*var, lst_arg);
	if (!(*var)->c_spec && **str)
		(*var)->input->i = *(*str)++;
	return (*var);
}

int		ft_pfmain_var(char *print, const char **str, va_list lst_arg)
{
	static t_var	*var;
	int				ret;

	ret = 0;
	if (**str == '%')
	{
		(*str)++;
		var = ft_pfmain_var_init(&var, str, lst_arg);
		ret = ft_pfvar_cal(var);
		print = var->flag->minus || var->flag->zero ? \
			ft_pfflag_process(print, var) : \
			ft_pfwidpre_widprocess(print, var);
		free(var->input->out);
	}
	if (!ft_strchr(*str, '%'))
		ft_pfmain_var_del(&var);
	return (ret);
}

int		ft_pfmain_str(char *print, const char **str)
{
	int		ret;
	char	*chk;

	chk = ft_strchr(*str, '%');
	ret = (chk ? (int)(chk - *str) : ft_strlen(*str));
	ft_strncpy(print, *str, ret);
	*str += ret;
	return (ret);
}

int		ft_printf(const char *arg, ...)
{
	int			ret;
	char		print[BUFF_SIZE];
	const char	*str;
	va_list		lst_arg;

	va_start(lst_arg, arg);
	str = arg;
	ret = 0;
	if (str)
	{
		while (*str)
			ret += *str == '%' ? \
				ft_pfmain_var(print + ret, &str, lst_arg) : \
				ft_pfmain_str(print + ret, &str);
		write(1, print, ret);
	}
	va_end(lst_arg);
	return (ret);
}
