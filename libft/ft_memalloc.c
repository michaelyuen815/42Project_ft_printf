/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:08:25 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/03 00:35:08 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**bytes function of creating a new pointer
**with size (size) & initial value 0
*/

void	*ft_memalloc(size_t size)
{
	void	*ret;

	if (!(ret = (void*)malloc(size)))
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
