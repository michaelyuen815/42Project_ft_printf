/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 01:11:47 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/15 01:11:53 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_flag	*ft_pfflag_init(t_var *var, const char **str)
{
	t_flag *ret;

	ret = var->flag;
	ret->minus = 0;
	ret->plus = 0;
	ret->space = 0;
	ret->hash = 0;
	ret->zero = 0;
	ret->decimal = 0;
	while (ft_strchr(FLAG, **str) && **str)
	{
		ret->minus |= **str == '-';
		ret->plus |= **str == '+';
		ret->space |= **str == ' ';
		ret->hash |= **str == '#';
		ret->zero |= **str == '0';
		ret->decimal |= **str == '\'';
		(*str)++;
	}
	return (ret);
}

void	ft_pfflag_ctrl(t_var *var)
{
	if (!SPEC_SIGN(var->i_spec))
	{
		var->flag->plus = 0;
		var->flag->space = 0;
	}
	if (var->i_spec <= 4)
		var->flag->hash = 0;
	if (var->i_prec != -1 && var->c_spec != 'c' && var->c_spec != 's')
		var->flag->zero = 0;
	if (!SPEC_DEC(var->i_spec))
		var->flag->decimal = 0;
	if (var->flag->plus && var->flag->space)
		var->flag->space = 0;
	if (var->flag->minus && var->flag->zero)
		var->flag->zero = 0;
}

int		ft_pfflag_len(t_var *var)
{
	int		ret;
	char	*src;

	ret = 0;
	src = var->input->out;
	if ((var->flag->plus || var->flag->space) && ft_isdigit(*src))
		ret++;
	else if (var->flag->hash && var->i_spec == 5 && !var->ret[LEN_PRE] && \
		(ft_strcmp(src, "0") || !var->ret[LEN_SRC]))
		ret++;
	else if (var->c_spec == 'p')
		ret += 2;
	else if (var->flag->hash && ft_strcmp(src, "0") && var->i_spec == 6)
		ret += 2;
	var->ret[LEN_FLAG] = ret;
	return (ret);
}

char	*ft_pfflag_process(char *print, t_var *var)
{
	char	*src;

	src = var->input->out;
	if ((var->flag->plus || var->flag->space) && ft_isdigit(*src))
		*print = var->flag->space ? ' ' : '+';
	else if (var->flag->hash && var->i_spec == 5 && !var->ret[LEN_PRE] && \
		(ft_strcmp(src, "0") || !var->ret[LEN_SRC]))
		*print = '0';
	else if (var->c_spec == 'p' || \
		(var->flag->hash && ft_strcmp(src, "0") && var->i_spec == 6))
		ft_strncpy(print, (BL_UP(var->c_spec) ? "0X" : "0x"), 2);
	else if (SPEC_SIGN(var->i_spec) && *src == '-')
		print[var->ret[LEN_FLAG]++] = '-';
	if (var->flag->zero && var->ret[LEN_WID])
		ft_pfwidpre_widprocess(print + var->ret[LEN_FLAG], var);
	else
		ft_pfwidpre_preprocess(print + var->ret[LEN_FLAG], var);
	return (print);
}
