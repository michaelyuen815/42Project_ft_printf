/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:00:50 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 21:05:23 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**String functions of returning string of
**return of pointer function *f to every character in string *s with index
*/

char*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*ret;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ret = ft_strnew(len);
	while (len-- > 0 && ret)
		ret[len] = f(len, s[len]);
	return (ret);
}
