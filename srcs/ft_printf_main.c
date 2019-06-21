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

/*
** int printf ( const char * format, ... );
** prototype: %[flags][width][.precision][length]specifier
** flags option: #0-+ and space
** width parameter
** specifier % (print %)
** specifier c(char), s(string), p(ptr)
** specifier d, i(int), o(oct), u(unsigned int),
** 		xX (hex) with length option hh, h, l , ll
** specifier f with length option l, L
** bonus specifier e, g
** bonus flags: *
** bonus specifier b(binary)
*/

/*
** function of free struct var when it's not necessary
*/

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

/*
** function of organizing parameters into struct var
** step 1: if var is not setup, preserve memory for related items
** step 2: setup flag by function "ft_pfflag_init"
** step 3: setup width(i_width) by function "ft_pfwidpre_init"
** step 4: setup precision (i_prec) by fcuntion  "ft_pfwidpre_init"
**			if '.' does not exist, set i_prec as -1 (defaulted)
** step 5: setup length (len) by function "ft_pflen_init"
** step 6: setup speicifer (c_spec) by taking next char
**			take NULL if next char is not under SPEC
** step 7: adjust parameters by function "ft_pflen_ctrl"
** step 8: store variable to be converted from arguments by
**			function "ft_pfvar_init"
*/

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

/*
** function of handle varible format string in ft_printf
** step 1: organzie parameters into struct var (ft_pfmain_var_init)
** step 2: create output string and count (ret) length consisting
**			flag, width and precision (ft_pfvar_cal)
** step 3: copy the converted string into print
**			a. if '-' flag is on, run 1. flag 2. prec 3. width
**			b. if '0' flag is on, run 1. flag 2. width 3. prec
**			c. otherwise, run 1. width 2. flag, 3. prec
**			where:
**				flag function >> ft_pfflag_process
**				prec function >> ft_pfwidpre_preprocess
**				width function >> ft_pfwidpre_widprocess
** step 4: free var if there is no variable format string left
** step 5: return ret
*/

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

/*
** function of handling non-variable format string in ft_printf
** step 1: find ret >> the length of non-variable format string by
**			checking next '%'
** step 2: copy the content of non-variable format string into print
** step 3: move pointer of str forward by ret(th) char
** step 4: retrun ret
*/

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

/*
** main function of ft_printf
** step 1: setup arguments 1. str (print format) 2. lst_arg (variables)
** step 2: call functions based on first char:
**			a. run ft_pfmain_var if current first char is %
**			b. run ft_pfmain_str if current first char is not %
**		   return ret(no. of char to be printed) and print(char to be printed)
** step 3: repeat step 2 until all format is handled
** step 4: write ret(th) char for string print
*/

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
