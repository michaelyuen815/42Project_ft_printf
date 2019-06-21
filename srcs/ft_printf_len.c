/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:07:23 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/14 13:07:27 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_len	*ft_pflen_init(t_var *var, const char **str)
{
	t_len	*ret;

	ret = var->len;
	*ret = none;
	*ret = (!ft_strncmp(*str, "hh", 2) ? hh : *ret);
	*ret = (!ft_strncmp(*str, "ll", 2) ? ll : *ret);
	if (*ret)
		*str += 2;
	else
	{
		*ret = (**str == 'l' ? l : *ret);
		*ret = (**str == 'h' ? h : *ret);
		*ret = (**str == 'j' ? j : *ret);
		*ret = (**str == 'L' ? L : *ret);
		*ret = (**str == 'z' ? z : *ret);
		(*str) += (*ret ? 1 : 0);
	}
	ft_str_skipsp(str);
	return (ret);
}

void	ft_pflen_ctrl(t_var *var)
{
	ft_pfvar_size(var);
	if (*var->len == 99)
	{
		if (SPEC_INT(var->i_spec))
		{
			*var->len = 8;
			ft_pfvar_size(var);
		}
		else
			*var->len = 0;
	}
	if (var->i_spec <= 1)
		*(var->len) = 0;
	else if (SPEC_INT(var->i_spec))
		*(var->len) = *(var->len) <= 10 ? *(var->len) : 0;
	else if (SPEC_DEC(var->i_spec))
		*(var->len) = *(var->len) >= 10 ? *(var->len) : 0;
	if (BL_UP(var->c_spec) && var->c_spec != 'X')
		*(var->len) = 8;
	if (*(var->len))
		var->size = (var->size * (*(var->len) % 10)) / 4;
	ft_pfflag_ctrl(var);
}

t_ld	ft_pflen_divi(int digit)
{
	int		i;
	t_ld	divid;

	i = 0;
	divid = 1;
	if (digit > 0)
		while (++i < digit)
			divid *= 10;
	return (divid);
}
