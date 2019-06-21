/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:44:34 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 17:19:11 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite bytes functions bzero in lib <string.h>
**which reset value to 0 for 1st parameter pointer (*s) with size_t (n)
**use function ft_memset with value 0 and size_t n
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
