/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:57:00 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 15:37:30 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**ouptut functions of writing integer (n) with standard output
*/

void	ft_putnbr(int n)
{
	unsigned int tmp;

	tmp = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-');
		tmp = (unsigned int)n * -1;
	}
	if (tmp > 9)
		ft_putnbr(tmp / 10);
	ft_putchar(tmp % 10 + '0');
}
