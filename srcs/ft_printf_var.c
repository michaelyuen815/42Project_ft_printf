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

/*
** static struct table of related data based on specifier
** 1st data: specifiers
** 2nd data: size of specifier
** 3rd data: base (only apply for non 10 based)
** 4th data: pointer function of converting varible to string
*/

t_spec	g_spec[] =
{
	{"sp", 8, 4, &ft_pffunc_ptr},
	{"%c", 4, 0, &ft_pffunc_char},
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

/*
** function of finding size and base based on spec before adjustment of length
** and store result base and size under var
*/

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

/*
** function of storing variable (var->input) from argument
** a. if spec is %, store '%' in i(int)
** b. if spec is 's p', store variable in v(void *)
** c. if spec is 'c', store variable in i(int)
** d. if spec is 'd i u b o O x X', store variable with size limited
**		in ulli(unsigned long long int)
** e. if spec is 'f e E g G', store variable in ld (long double)
*/

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

/*
** function of converting variable to string and counting length
**		of filling into string print
** step 1: convert variable to string based on pointer function in g_spec
** step 2: if value in step 1 is 0 and spec is 'p d i u b o O x X' and
**			precision is 0, skip printing string in step 1
** step 3: count the length of converted string. If decide not to print in
**			step 2, lenght = 0
** step 4: count the precision with function "ft_pfwidpre_len"
** step 5: count the flag with function "ft_pfflag_len"
** step 6: count the required width by differing width and current length 
**			if width is larger than current length
*/

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
