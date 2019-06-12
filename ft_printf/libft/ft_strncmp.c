/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 21:26:06 by chyuen            #+#    #+#             */
/*   Updated: 2019/04/29 21:28:11 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite string functions strncmp in lib <string.h>
**return difference of first differing char between *s1 and *s2 within n char
**return 0 if *s1 and *s2 are identical within n char
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *us1;
	unsigned char *us2;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	if (!n)
		return (0);
	while (*us1 && *us2 && *us1 == *us2 && n > 0)
	{
		us1++;
		us2++;
		n--;
	}
	if (n > 0)
		return (*us1 - *us2);
	return (0);
}
