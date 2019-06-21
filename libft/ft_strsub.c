/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:13:52 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 21:19:34 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**String functions of returning a string
**from start(th) position and len character with allocated memory
**Return NULL when start + len > size of *s
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ret;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start + len)
		return (NULL);
	ret = ft_strnew(len);
	while (len-- && ret)
		ret[len] = s[start + len];
	return (ret);
}
