/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:57:15 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 21:16:18 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite bytes function of memcmp in lib <string.h>
**return difference of first differing bytes between *s1 and *s2
**if no difference is not found within n bytes, return 0
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ch_s1;
	unsigned char	*ch_s2;
	size_t			i;

	i = 0;
	ch_s1 = (unsigned char*)s1;
	ch_s2 = (unsigned char*)s2;
	while (i < n && ch_s1[i] == ch_s2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (ch_s1[i] - ch_s2[i]);
}
