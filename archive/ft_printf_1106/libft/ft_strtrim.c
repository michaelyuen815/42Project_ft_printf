/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:29:14 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 21:46:06 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**String functions of returning a string that
**removing space/tab at the beginning and end of string by:
**1. use while to remove the spaces/tab at the beginning
**2. use ft_strwolsp to count nbr of char before space/tab at the end
**3. use function ft_strsub with value in 2. to create string
*/

static size_t	ft_strwolsp(char const *s)
{
	size_t len;
	size_t len_sp;

	if (!*s)
		return (0);
	len = 0;
	while (*s)
	{
		len++;
		len_sp = (BL_WSP(*s) ? (len_sp + 1) : 0);
		s++;
	}
	return (len - (BL_WSP(*(s - 1)) ? len_sp : 0));
}

char			*ft_strtrim(char const *s)
{
	if (!s)
		return (NULL);
	while (*s && BL_WSP(*s))
		s++;
	return (ft_strsub(s, 0, ft_strwolsp(s)));
}
