/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:30:20 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 22:30:08 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite string functions strlcat in lib <string.h>
**append string *src to end of string *dest at most size - size of *dest - 1
**return total size of *dest and *src if size > size of dest
**return size + size of src if size <= size of dest
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t len;

	len = ft_strlen(dest);
	if (size <= len)
		return (size + ft_strlen(src));
	size -= (len + 1);
	while (*src && size-- > 0)
		dest[len++] = *(src++);
	dest[len] = 0;
	return (len + ft_strlen(src));
}
