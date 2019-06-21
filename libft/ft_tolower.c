/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:35:37 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 15:36:19 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**String functions of return lowercase char if int c is uppercase char
**return same value if int c is not uppercase char
*/

int	ft_tolower(int c)
{
	if (BL_UP(c))
		return (c + 32);
	return (c);
}
