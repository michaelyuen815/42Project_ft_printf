/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:51:29 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 15:38:24 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite ouptut functions putchar in lib <stdio.h>
**write character parameter (c) with standard output
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
