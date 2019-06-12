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

int ft_pfmain_var(char *print, const char *str, va_list lst_arg)
{
	int ret;

	ret = 0;
	if (*str == '%')
	{
		str++;
		ret = ft_pfvar_init(print, &str, lst_arg);
	}
	if (*str)
		ret += *str == '%' ? \
			ft_pfmain_var(print + ret, str, lst_arg) : \
			ft_pfmain_str(print + ret, str, lst_arg);
	return (ret);
}

int ft_pfmain_str(char *print, const char *str, va_list lst_arg)
{
	int ret;
	char *chk;

	chk = ft_strchr(str, '%');
	ret = (chk ? (int)(chk - str) : ft_strlen(str));
	ft_strncpy(print, str, ret);
	if (chk)
		ret += ft_pfmain_var(print + ret, str + ret, lst_arg);
	return (ret);
}

int	ft_printf(const char *arg, ...)
{
	int	ret;
	char print[BUFF_SIZE];
	const char	*str;
	va_list		lst_arg;

	va_start(lst_arg, arg);
	str = arg;
	ret = 0;
	if (str)
	{
		ret = *str == '%' ? \
			ft_pfmain_var(print, str, lst_arg) : \
			ft_pfmain_str(print, str, lst_arg);
		write(1, print, ret);
	}
	va_end(lst_arg);
	return (ret);
}