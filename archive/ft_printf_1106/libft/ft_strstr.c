/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:01:01 by chyuen            #+#    #+#             */
/*   Updated: 2019/04/29 21:07:22 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite string functions strnstr in lib <string.h>
**return the pointer in *haystack of where *needle is found
**return NULL if *needle is not found
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (!*haystack && !*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		i = 0;
		while (needle[i] && haystack[i] == needle[i])
			i++;
		if (!needle[i])
			return ((char*)haystack);
		haystack++;
	}
	return (0);
}
