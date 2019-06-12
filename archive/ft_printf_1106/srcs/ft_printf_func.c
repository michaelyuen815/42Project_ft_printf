/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:09:15 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/28 16:09:29 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_pffunc_boxx(t_print *t_list)
{
	int		base;
	int		size;
	int		i;
	char	*ret;

	ft_pfvar_size(t_list, &size, &base);
	size = size * 8 / base - 1;
	while (size > 0 && \
	!(t_list->output->ulli >> size * base & (15 >> (4 - base))))
		size--;
	size++;
	ret = ft_strnew(size);
	i = 0;
	while (size--)
		ret[i++] = BL_UP(t_list->c_spec) ?\
		HEX_U[(t_list->output->ulli >> size * base) & (15 >> (4 - base))] :\
		HEX_L[(t_list->output->ulli >> size * base) & (15 >> (4 - base))];
	ret[i] = 0;
	return (ret);
}

static char	*ft_pffunc_itoa(unsigned long long int nbr, char bl_neg)
{
	size_t	len;
	size_t	i;
	char	*ret;
	char	tmp[25];

	len = 0;
	if (!nbr)
		tmp[len++] = '0';
	while (nbr)
	{
		tmp[len++] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (bl_neg)
		tmp[len++] = '-';
	ret = ft_strnew(len);
	i = -1;
	while (++i < len)
		ret[i] = tmp[len - 1 - i];
	return (ret);
}

char		*ft_pffunc_diu(t_print *t_list)
{
	int		base;
	int		size;
	char	bl_neg;

	bl_neg = 0;
	ft_pfvar_size(t_list, &size, &base);
	if (!ft_strchr("uU", t_list->c_spec))
	{
		if ((bl_neg = t_list->output->ulli >> (size * 8 - 1) & 1))
			t_list->output->ulli = 1 + (~t_list->output->lli & \
				(BITS_MAX_TOL >> (BITS_MAX - size * 8)));
	}
	return (ft_pffunc_itoa(t_list->output->ulli, bl_neg));
}

char		*ft_pffunc_char(t_print *t_list)
{
	char *ret;

	ret = ft_strnew(1);
	ret[0] = (char)t_list->output->i;
	return (ret);
}

char		*ft_pffunc_ptr(t_print *t_list)
{
	char	*tmp;
	char	*ret;

	if (t_list->c_spec == 'p')
	{
		tmp = ft_pffunc_boxx(t_list);
		if (!ft_strequ("0", tmp) && ft_strlen(tmp) < 9)
			ret = ft_strjoin("1", tmp);
		else
			ret = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (ret);
	}
	else if (t_list->output->v)
		return (ft_strdup((char*)t_list->output->v));
	else
		return (ft_strdup("(null)"));
}
