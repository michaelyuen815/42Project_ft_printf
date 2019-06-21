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

t_spec	g_spec[] =
{
	{"sp", 8, 4, &ft_pffunc_ptr},
	{"%Cc", 4, 0, &ft_pffunc_char},
	{"Ddi", 4, 0, &ft_pffunc_diu},
	{"uU", 4, 0, &ft_pffunc_diu},
	{"b", 4, 1, &ft_pffunc_box},
	{"oO", 4, 3, &ft_pffunc_box},
	{"xX", 4, 4, &ft_pffunc_box},
	{"fF", 8, 0, &ft_funcf_feg},
	{"eE", 8, 0, &ft_funcf_feg},
	{"gG", 8, 0, &ft_funcf_feg},
	{"", 4, 0, &ft_pffunc_char}
};

int		ft_pfvar_size(t_var *var)
{
	size_t	i;

	i = 0;
	while (!ft_strchr(g_spec[i].spec, var->c_spec))
		i++;
	var->i_spec = var->c_spec ? i : SPEC_END;
	var->base = (int)g_spec[i].base;
	var->size = (int)g_spec[i].bitsize;
	return (1);
}

void	ft_pfvar_init(t_var *var, va_list lst_arg)
{
	var->input->ld = 0;
	if (var->c_spec == '%')
		var->input->i = '%';
	else if (!var->i_spec)
		var->input->v = va_arg(lst_arg, void*);
	else if (var->i_spec == 1)
		var->input->i = va_arg(lst_arg, int);
	else if (SPEC_INT(var->i_spec))
		var->input->ulli = va_arg(lst_arg, t_ulli) & \
			(BT_MAX >> (B_MAX - var->size * 8));
	else if (SPEC_DEC(var->i_spec) && var->size == 8)
		var->input->ld = (t_ld)va_arg(lst_arg, double);
	else if (SPEC_DEC(var->i_spec) && var->size == 10)
		var->input->ld = va_arg(lst_arg, t_ld);
}

int		ft_pfvar_cal(t_var *var)
{
	int ret;

	var->input->out = g_spec[var->i_spec].pro(var);
	var->ret[LEN_SRC] = (SPEC_INT(var->i_spec) || var->c_spec == 'p') && \
		!var->i_prec && !ft_strcmp(var->input->out, "0") ? \
			0 : var->ret[LEN_SRC];
	ret = var->ret[LEN_SRC];
	ret += ft_pfwidpre_len(var);
	ret += ft_pfflag_len(var);
	var->ret[LEN_WID] = (var->i_width <= ret ? 0 : var->i_width - ret);
	ret += var->ret[LEN_WID];
	return (ret);
}
