/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:42:43 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/11 20:42:46 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_flag *ft_pfflag_init(const char **str)
{
	t_flag *ret;

	if (!(ret = (t_flag*)malloc(sizeof(t_flag))))
		return (NULL);
	ret->minus = 0;
	ret->plus = 0;
	ret->space = 0;
	ret->hash = 0;
	ret->zero = 0;
	ret->Decimal = 0;
	while (ft_strchr(FLAG, **str))
	{
		ret->minus |= **str == '-';
		ret->plus |= **str == '+';
		ret->space |= **str == ' ';
		ret->hash |= **str == '#';
		ret->zero |= **str == '0';
		ret->Decimal |= **str == '''';
		(*str)++;
	}
	return (ret);
}