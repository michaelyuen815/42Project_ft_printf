/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:15:47 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/14 17:15:49 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_pffunc_box(t_var *var)
{
	int		i_ret;
	int		i;
	char	*ret;
	char	tmp;

	i_ret = var->size * 8 / var->base - (var->size * 8 % var->base ? 0 : 1);
	while (i_ret > 0 && \
	!(var->input->ulli >> i_ret * var->base & (15 >> (4 - var->base))))
		i_ret--;
	i_ret++;
	ret = ft_strnew(i_ret);
	var->ret[LEN_SRC] = i_ret;
	i = 0;
	while (i_ret--)
	{
		tmp = (var->input->ulli >> i_ret * var->base) & (15 >> (4 - var->base));
		ret[i++] = BL_UP(var->c_spec) ? HEX_U[(int)tmp] : HEX_L[(int)tmp];
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_pffunc_char(t_var *var)
{
	char	*ret;

	var->ret[LEN_SRC] = 0;
	if (!var->input->i && var->i_spec == SPEC_END)
		return (ft_strdup(""));
	var->ret[LEN_SRC] = 1;
	ret = ft_strnew(1);
	ret[0] = var->input->i < 256 ? (char)var->input->i : 0;
	return (ret);
}

char	*ft_pffunc_ptr(t_var *var)
{
	char	*ret;

	if (var->c_spec == 'p')
		ret = ft_pffunc_box(var);
	else
	{
		ret = var->input->v ? \
		ft_strdup((char*)var->input->v) : ft_strdup("(null)");
		var->ret[0] = ft_strlen(ret);
	}
	return (ret);
}

char	*ft_pffunc_itoa(t_var *var, char bl_neg)
{
	size_t	i;
	size_t	len;
	t_ulli	src;
	char	*ret;

	i = 0;
	len = (size_t)var->ret[LEN_SRC];
	src = var->input->ulli;
	ret = ft_strnew(len);
	ret[0] = bl_neg ? '-' : 0;
	ret[0] = src ? ret[0] : '0';
	while (src)
	{
		ret[len - ++i] = src % 10 + '0';
		src /= 10;
	}
	return (ret);
}

char	*ft_pffunc_diu(t_var *var)
{
	int		i_ret;
	t_ulli	src;
	char	bl_neg;

	bl_neg = 0;
	if (SPEC_SIGN(var->i_spec))
	{
		if ((bl_neg = var->input->ulli >> (var->size * 8 - 1) & 1))
			var->input->ulli = 1 + (~var->input->lli & \
				(BT_MAX >> (B_MAX - var->size * 8)));
	}
	src = var->input->ulli;
	i_ret = src ? 0 : 1;
	while (src)
	{
		i_ret++;
		src /= 10;
	}
	i_ret += bl_neg ? 1 : 0;
	var->ret[LEN_SRC] = i_ret;
	return (ft_pffunc_itoa(var, bl_neg));
}
