/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:44:19 by chyuen            #+#    #+#             */
/*   Updated: 2019/04/29 14:48:45 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**rewrite string functions strlen in lib <string.h>
**return size of string *str
*/

size_t	ft_strlen(const char *str)
{
	size_t ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}
