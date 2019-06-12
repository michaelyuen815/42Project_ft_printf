/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:19:33 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 18:24:08 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite bytes function of memchr in lib <string.h>
**return the pointer where value c is found.
**if value c is not found within n bytes, return NULL
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ch_s;

	i = 0;
	ch_s = (unsigned char*)s;
	while (i < n && ch_s[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (0);
	else
		return ((void*)(s + i));
}
