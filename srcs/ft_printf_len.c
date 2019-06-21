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

/*
** function of setup length during organizing parameters
** step 1: setup length (len) value = 0 (none)
** step 2: change value of len if correspoding length specifier are found
**			i. check double char length spec with ft_strncmp, then
**			ii. check single char lenght spec
*/

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

/*
** function of adjusting length before setuping variables
** step 1: counting size and group of spec by function "ft_pfvar_size"
** step 2: if len is 99 (length = z), change the length to 8 and redo step 1
** step 3: if spec is '% c s p', length is changed to 0 (none);
** step 4: if spec is 'd i u b o x X' and length is large than 10 (L),
**			change to 0 (none)
** step 5: if spec is 'f e E g G' and length is between 1 and 10
**			(hh, h, l, ll), change length to 0 (none)
** step 6: calculate the size = size * (remainder of length divided by 10) / 4
*/

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

/*
** function of finding first divider of handling double
** e.g. if value = 345, first divider = 1000
** first divider = 10 ^ (no. of digit excluding decimal + 1)
*/

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
