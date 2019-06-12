/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:04:55 by chyuen            #+#    #+#             */
/*   Updated: 2019/04/29 20:29:00 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**rewrite string functions strcat in lib <string.h>
**append string *src to end of string *dest and return string *dest
*/

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t len;

	len = ft_strlen(dest);
	while (*src)
		dest[len++] = *(src++);
	dest[len] = 0;
	return (dest);
}
