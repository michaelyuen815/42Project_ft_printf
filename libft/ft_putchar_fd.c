/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:34:06 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 13:34:32 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite ouptut functions fputc in lib <stdio.h>
**write character parameter (c) with file descriptor (fd)
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
