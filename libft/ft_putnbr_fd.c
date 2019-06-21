/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:37:03 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 15:38:41 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**ouptut functions of writing integer (n) with file descriptor (fd)
*/

void	ft_putnbr_fd(int n, int fd)
{
	long tmp;

	tmp = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = (long)n * -1;
	}
	if (tmp > 9)
		ft_putnbr_fd(tmp / 10, fd);
	ft_putchar_fd(tmp % 10 + '0', fd);
}
