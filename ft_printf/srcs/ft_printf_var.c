/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:30:33 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/11 20:30:36 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int ft_pfvar_init(char *print, char **str, va_list lst_arg)
{
	t_var *var;

	if (!(ret = (t_var*)malloc(sizeof(t_var))))
		return (NULL);
	ret->flag = ft_pfflag_init(str, bl_arg);
}