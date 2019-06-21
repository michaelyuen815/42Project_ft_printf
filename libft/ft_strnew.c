/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:13:47 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 20:56:58 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**String functions of creating a new blank string with allocated memory
*/

char	*ft_strnew(size_t size)
{
	char *ret;

	if (!(ret = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	ret[size] = 0;
	while (size-- > 0)
		ret[size] = 0;
	return (ret);
}
