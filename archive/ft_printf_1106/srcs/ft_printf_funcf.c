/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:52:23 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/04 16:52:25 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_funcf_float(t_print *t_list)
{
	char	*ret;
	int base;
	int size;
	//char bl_neg;

	ret = NULL;
	ft_pfvar_size(t_list, &size, &base);
	//bl_neg = t_list->output->ulli >> (size * 8 - 1) & 1;
	//printf("%s\n", ft_pffunc_itoa(, 0));
	return (NULL);
}
