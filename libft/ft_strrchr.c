/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:53:17 by chyuen            #+#    #+#             */
/*   Updated: 2019/04/29 20:57:48 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**rewrite string functions strchr in lib <string.h>
**1. return pointer of position last integer value c is found in string *str
**2. return NULL if int c is not found in string *str
*/

char	*ft_strrchr(const char *str, int c)
{
	char *ch;

	ch = 0;
	while (*str)
	{
		if (*str == c)
			ch = (char*)str;
		str++;
	}
	if (!c)
		return ((char*)str);
	return (ch);
}
