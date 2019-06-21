/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:20:27 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 21:57:09 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**String functions of returning string of joining *s1 and *s2
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	if (s1)
		while (*s1 && ret)
			ret[i++] = *s1++;
	if (s2)
		while (*s2 && ret)
			ret[i++] = *s2++;
	return (ret);
}
