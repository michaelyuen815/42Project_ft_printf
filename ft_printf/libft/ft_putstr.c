/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:52:25 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/02 12:56:47 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite ouptut functions puts in lib <stdio.h>
**write string parameter (*s) with standard output
*/

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}
