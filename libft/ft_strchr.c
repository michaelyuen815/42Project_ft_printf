/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:48:46 by chyuen            #+#    #+#             */
/*   Updated: 2019/04/29 20:50:30 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**rewrite string functions strchr in lib <string.h>
**1. return pointer of position 1st integer value c is found in string *str
**2. return NULL if int c is not found in string *str
*/

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != c)
		str++;
	if (!*str && c)
		return (0);
	return ((char*)str);
}
