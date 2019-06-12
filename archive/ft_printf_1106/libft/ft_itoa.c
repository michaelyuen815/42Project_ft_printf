/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:46:28 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 21:55:21 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Reverse function of ft_atoi
**which return a string from integer n
**method: storing the digits into tmp[] starting from single digit
*/

char	*ft_itoa(int n)
{
	int		sign;
	size_t	len;
	size_t	i;
	char	tmp[13];
	char	*ret;

	sign = (n < 0 ? -1 : 1);
	len = 0;
	if (!n)
		tmp[len++] = '0';
	while (n)
	{
		tmp[len++] = n % 10 * sign + '0';
		n /= 10;
	}
	if (sign == -1)
		tmp[len++] = '-';
	ret = ft_strnew(len);
	i = -1;
	while (++i < len && ret)
		ret[i] = tmp[len - 1 - i];
	if (ret)
		ret[len] = 0;
	return (ret);
}
