/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:16:05 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/15 16:16:06 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_funcf_len(t_var *var)
{
	t_ld	src;
	int		ret;

	src = var->input->ld;
	ret = 0;
	var->i_prec = (var->i_prec < 0) ? 6 : var->i_prec;
	if (!src)
		ret++;
	else if (src > 1 || src < -1)
		while ((src > 1 || src < -1) && ++ret)
			src /= 10;
	else
		while ((int)src == 0 && --ret)
			src *= 10;
	var->ret[LEN_SRC] = ret;
	var->ret[LEN_PRE] = var->i_prec;
	return (ret);
}

t_ld	ft_funcf_round(t_var *var, char chk_f, int sign, t_ld divid)
{
	int		i;
	int		last;
	t_ld	src;

	i = -1;
	if (chk_f)
		last = (var->ret[LEN_SRC] < 0 ? 1 : var->ret[LEN_SRC]);
	else
		last = 1 + (var->ret[LEN_SRC] < 0 ? var->ret[LEN_SRC] * -1 : 0);
	last += var->ret[LEN_PRE];
	src = var->input->ld * sign;
	while (++i < last)
	{
		src -= (t_ulli)(src / divid) * divid;
		divid /= 10;
	}
	return ((t_ulli)(src / divid) >= 5 ? divid * 10 : 0);
}

char	*ft_funct_fout(t_var *var, int len, int sign, t_ld divid)
{
	int		i;
	char	*ret;

	i = -1;
	ret = ft_strnew(len);
	if (sign == -1)
		ret[++i] = '-';
	while (++i < len)
	{
		if (i == var->ret[LEN_SRC] + (sign == -1) || \
		(i == 1 + (sign == -1) && var->ret[LEN_SRC] < 0))
			ret[i++] = '.';
		ret[i] = (t_ulli)(var->input->ld / divid * sign) + '0';
		var->input->ld -= \
		(t_ulli)(var->input->ld / divid * sign) * divid * sign;
		divid /= 10;
	}
	var->ret[LEN_SRC] = len;
	return (ret);
}

char	*ft_funct_eout(t_var *var, int len, int sign, t_ld divid)
{
	int		i;
	char	*ret;

	i = -1;
	ret = ft_strnew(len);
	if (sign == -1)
		ret[++i] = '-';
	while (!(t_ulli)(var->input->ld / divid * sign))
		divid /= 10;
	while (++i < var->ret[LEN_PRE] + 1 + (var->ret[LEN_PRE] > 0))
	{
		if (i == 1 + (sign == -1))
			ret[i++] = '.';
		ret[i] = (t_ulli)(var->input->ld / divid * sign) + '0';
		var->input->ld -= \
			(t_ulli)(var->input->ld / divid * sign) * divid * sign;
		divid /= 10;
	}
	ret[i++] = BL_UP(var->c_spec) ? 'E' : 'e';
	ret[i++] = var->ret[LEN_SRC] >= 0 ? '+' : '-';
	ret[i++] = var->ret[LEN_SRC] / 10 + '0';
	ret[i++] = var->ret[LEN_SRC] % 10 * (var->ret[LEN_SRC] < 0 ? -1 : 1) + '0';
	var->ret[LEN_SRC] = len;
	return (ret);
}

char	*ft_funcf_feg(t_var *var)
{
	int		sign;
	int		len;
	t_ld	divid;
	char	chk_f;

	sign = var->input->ld >= 0 ? 1 : -1;
	len = ft_funcf_len(var);
	divid = ft_pflen_divi(len);
	if ((chk_f = (var->i_spec == 7 || (var->i_spec == 9 && \
		(len <= var->ret[LEN_PRE] && len >= -4)))))
		len = len > 0 ? len : 1;
	else
		len = 5 + (len >= 100 || len <= -100);
	len += var->ret[LEN_PRE] > 0 ? var->ret[LEN_PRE] + 1 : 0;
	len += (sign == -1 ? 1 : 0);
	var->input->ld += ft_funcf_round(var, chk_f, sign, divid) * sign;
	if (chk_f)
		return (ft_funct_fout(var, len, sign, divid));
	else
		return (ft_funct_eout(var, len, sign, divid));
}
