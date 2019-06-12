/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:59:35 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/27 16:59:44 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_len	*ft_pflen_len_init(const char **str, char bl_arg)
{
	t_len *ret;

	if (!(ret = (t_len*)malloc(sizeof(t_len))))
		return (NULL);
	*ret = none;
	if (!bl_arg)
		return (ret);
	*ret = (!ft_strncmp(*str, "hh", 2) ? hh : *ret);
	*ret = (!ft_strncmp(*str, "ll", 2) ? ll : *ret);
	if (*ret)
		(*str)++;
	else
	{
		*ret = (**str == 'l' ? l : *ret);
		*ret = (**str == 'h' ? h : *ret);
		*ret = (**str == 'j' ? j : *ret);
		*ret = (**str == 'L' ? L : *ret);
	}
	if (*ret)
		(*str)++;
	ft_str_skipsp(str);
	return (ret);
}

int		ft_pflen_widprec_init(const char **str, char bl_prec, va_list lst_arg)
{
	int ret;

	ret = 0;
	if (bl_prec && **str == '.')
		(*str)++;
	if (**str == '*')
	{
		(*str)++;
		ret = va_arg(lst_arg, int);
		ret = (ret < 0 ? 0 : ret);
	}
	else if (ft_isdigit(**str))
	{
		while (ft_isdigit(**str))
			ret = ret * 10 + *(*str)++ - '0';
	}
	ft_str_skipsp(str);
	return (ret);
}

/*
**a. Flag (plus, space, hash)
**b. Prec	(ret)
**c. Width (zero)
**
**minus
**1. Flag 2. Prec 3. Width
**
**Zero
**1. Flag 2. Width 3. prec
**
**(!zero && !minus)
**1. Width 2. Flag 3. prec
*/

char	*ft_pflen_zero_process(char *ret, int len)
{
	int i;

	i = 0;
	while (i < len)
		ret[i++] = '0';
	return (ret);
}

char	*ft_pflen_prec_process(char *ret, t_print *t_list, int len_ext, int len)
{
	int		hash;
	int		i;
	char	*src;

	i = len;
	hash = 0;
	src = t_list->output->s_out;
	if (ft_strchr("pdiuUboxX", t_list->c_spec))
	{
		i = (!t_list->i_prec && ft_strequ(src, "0")) ? 0 : ft_strlen(src);
		i -= (*src == '-' ? 1 : 0);
		hash = (t_list->i_prec <= i ? hash : t_list->i_prec - i);
		ft_pflen_zero_process(ret, hash);
	}
	ft_strncpy(ret + hash, src + (*src == '-' ? 1 : 0), i);
	i += hash;
	if (t_list->flag->minus)
		ft_pflen_wid_process(ret + i, t_list, len_ext - i, len - i);
	return (ret);
}

char	*ft_pflen_wid_process(char *ret, t_print *t_list, int len_ext, int len)
{
	int i;

	i = 0;
	while (i < len_ext - len)
		ret[i++] = t_list->flag->zero ? '0' : ' ';
	if (t_list->flag->zero && !t_list->flag->minus)
		ft_pflen_prec_process(ret + i, t_list, len_ext - i, len);
	else if (!t_list->flag->zero && !t_list->flag->minus)
		ft_pfflag_process(ret + i, t_list, len_ext - i, len);
	return (ret);
}
