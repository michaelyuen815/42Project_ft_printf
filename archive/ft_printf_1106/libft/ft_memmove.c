/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:26:48 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 21:23:11 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite bytes function of memcpy in lib <string.h>
**memcpy and memmove are the same if there is no overlapping
**If there is overlapping:
**memcpy copy the overlapped value into dst
**memmove copy origin value of src into dst
**
**drawback of memove: extra time of processing to prevent overlap
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*ch_dst;
	unsigned char	*ch_src;

	ch_src = (unsigned char*)src;
	ch_dst = (unsigned char*)dst;
	i = -1;
	if (ch_dst > ch_src)
		while (len--)
			ch_dst[len] = ch_src[len];
	else
		while (++i < len)
			ch_dst[i] = ch_src[i];
	return (ch_dst);
}
