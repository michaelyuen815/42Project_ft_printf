/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:29:11 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 15:37:47 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite ouptut functions fputs in lib <stdio.h>
**write string parameter (*s) with file descriptor (fd)
*/

void	ft_putstr_fd(char const *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}
