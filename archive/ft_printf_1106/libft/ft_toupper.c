/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 15:32:55 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/01 15:35:30 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**String functions of return uppercase char if int c is lowercase char
**return same value if int c is not lowercase char
*/

int	ft_toupper(int c)
{
	if (BL_LW(c))
		return (c - 32);
	return (c);
}
