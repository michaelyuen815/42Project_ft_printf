/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:25:42 by chyuen            #+#    #+#             */
/*   Updated: 2019/04/29 20:29:09 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite string functions strncat in lib <string.h>
**append string *src to end of string *dest up to n characters
**return string *dest
*/

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;

	len = ft_strlen(dest);
	while (*src && n--)
		dest[len++] = *(src++);
	dest[len] = 0;
	return (dest);
}
