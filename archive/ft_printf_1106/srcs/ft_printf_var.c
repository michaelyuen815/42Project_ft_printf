/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:58:39 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/27 16:58:50 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	g_spec[] =
{
	{"sp", 8, 4, &ft_pffunc_ptr},
	{"%Cc", 4, 0, &ft_pffunc_char},
	{"diu", 4, 0, &ft_pffunc_diu},
	{"U", 8, 0, &ft_pffunc_diu},
	{"b", 4, 1, &ft_pffunc_boxx},
	{"oO", 4, 3, &ft_pffunc_boxx},
	{"xX", 4, 4, &ft_pffunc_boxx},
	//{"feg", 8, 0, &ft_funcf_float},
	{SPEC, 0, 0, &ft_pffunc_ptr}
};

int			ft_pfvar_size(t_print *t_list, int *size, int *base)
{
	size_t	i;

	i = 0;
	while (!ft_strchr(g_spec[i].spec, t_list->c_spec))
		i++;
	if (!g_spec[i].bitsize)
		return (0);
	*base = (int)g_spec[i].base;
	if (!size)
		return (1);
	*size = (int)g_spec[i].bitsize;
	if (*(t_list->len) && t_list->c_spec != 'U')
		*size = (*size * (*(t_list->len) % 10)) / 4;
	return (1);
}

static int	ft_pfvar_check(t_print *t_list)
{
	if (!ft_strchr(SPEC, t_list->c_spec))
		return (0);
	if (ft_strchr("%Ccsp", t_list->c_spec))
		return (*(t_list->len) == 0);
	else if (ft_strchr("diuUboxX", t_list->c_spec))
		return (*(t_list->len) <= 10);
	else if (ft_strchr("feg", t_list->c_spec))
		return ((*(t_list->len) % 18) == 0);
	else
		return (!ft_printf("missing control for spec %c\n", t_list->c_spec));
	return (1);
}

static int	ft_pfvar_varinit(t_print *t_list, va_list lst_arg)
{
	int		base;
	int		size;

	if (!ft_pfvar_size(t_list, &size, &base))
		return (0);
	t_list->output->ld = 0;
	if (t_list->c_spec == '%')
		t_list->output->i = '%';
	else if (ft_strchr("sp", t_list->c_spec))
		t_list->output->v = va_arg(lst_arg, void*);
	else if (t_list->c_spec == 'c')
		t_list->output->i = va_arg(lst_arg, int);
	else if (ft_strchr("diuUboxX", t_list->c_spec))
		t_list->output->ulli = va_arg(lst_arg, unsigned long long int) & \
		(BITS_MAX_TOL >> (BITS_MAX - size * 8));
	else if (ft_strchr("diuUboxX", t_list->c_spec) && !*(t_list->len))
		t_list->output->dbl = va_arg(lst_arg, double);
	else if (size == 16)
		t_list->output->ld = va_arg(lst_arg, long double);
	else
		return (0);
	return (1);
}

int			ft_pfvar_init\
	(t_print *t_list, const char **str, va_list lst_arg)
{
	size_t len;

	t_list->output = NULL;
	if (!lst_arg)
		return (0);
	if (!ft_pfvar_check(t_list))
		return (0);
	if (!ft_pfflag_check(t_list))
		return (0);
	if (!(t_list->output = (t_output*)malloc(sizeof(t_output))))
		return (0);
	if (t_list->b_arg)
		return (ft_pfvar_varinit(t_list, lst_arg));
	else
	{
		len = ft_strchr(*str, '%') ?\
			(ft_strchr(*str, '%') - *str) : ft_strlen(*str);
		t_list->output->s_out = ft_strsub(*str, 0, len);
		(*str) += len;
	}
	return (1);
}

char		*ft_pfvar_output(t_print *t_list)
{
	size_t	i;
	char	*ret;

	i = 0;
	while (!ft_strchr(g_spec[i].spec, t_list->c_spec))
		i++;
	ret = g_spec[i].f(t_list);
	return (ret);
}
