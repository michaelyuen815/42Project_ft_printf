/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:03:33 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 17:53:49 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite bytes function of memcpy in lib <string.h>
**copy n bytes from src to det and return pointer of *dst
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ch_dst;
	unsigned char	*ch_src;

	ch_dst = (unsigned char*)dst;
	ch_src = (unsigned char*)src;
	while (n--)
		ch_dst[n] = ch_src[n];
	return (dst);
}
