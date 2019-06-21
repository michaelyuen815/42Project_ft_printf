/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_widpre.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:36:43 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/13 14:36:46 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
** function of setup width/precision during organizing parameters
** step 1: default value = -1.
** step 2: read the number from format string until no number char is found
** step 3: if there is char '*', read next argument as value of precision/width
**			if value is -ve:
**			a. turn on '-' flag and keep absolute value for width
**			b. keep default value (-1) for precision
*/

int		ft_pfwidpre_init(\
	t_var *var, const char **str, char bl_prec, va_list lst_arg)
{
	int ret;

	ret = 0;
	if (bl_prec)
		while (**str == '.')
			(*str)++;
	ret = ft_isdigit(**str) || bl_prec ? 0 : -1;
	while (ft_isdigit(**str))
		ret = ret * 10 + *(*str)++ - '0';
	if (**str == '*')
	{
		(*str)++;
		ret = va_arg(lst_arg, int);
		if (ret < 0 && !bl_prec)
		{
			var->flag->minus = 1;
			ret *= -1;
		}
	}
	ft_str_skipsp(str);
	return (ret);
}

/*
**a. Flag (plus, space, hash)
**b. Prec	(ret)
**c. Width (zero)
**
**minus
**1. Flag 2. Prec 3. Width
**
**Zero
**1. Flag 2. Width 3. prec
**
**(!zero && !minus)
**1. Width 2. Flag 3. prec
*/

/*
** function of counting length required for prec after converting var to str
** a. if spec is 's' and prec is less than length of converted string
**		(ret[LEN_SRC]), return difference between them (-ve)
** b. if spec is 'd i u b o O x X' and precision is larger than
**		ret[LEN_SRC] excluding sign '-',
**		return difference between them (+ve)
*/

int		ft_pfwidpre_len(t_var *var)
{
	int	tmp;
	int ret;

	ret = 0;
	if (var->i_spec == 1)
		ret = 0;
	else if (var->c_spec == 's' && var->i_prec >= 0)
		ret = var->i_prec >= var->ret[LEN_SRC] ? \
			0 : var->i_prec - var->ret[LEN_SRC];
	else if (SPEC_INT(var->i_spec) || var->c_spec == 'p')
	{
		tmp = var->ret[LEN_SRC] - (*var->input->out == '-' ? 1 : 0);
		ret = var->i_prec <= tmp ? 0 : var->i_prec - tmp;
	}
	var->ret[LEN_PRE] = ret;
	return (ret);
}

/*
** function of filling width (" "/"0") into string print after counting len
** a. fill ' ' for every width unit
** b. fill '0' if '0' flag is on
** then run other filling functio:
**		a. ft_pfwidpre_preprocess
**		b. ft_pfflag_process
*/

char	*ft_pfwidpre_widprocess(char *print, t_var *var)
{
	int i;

	i = 0;
	while (i < var->ret[LEN_WID])
		print[i++] = var->flag->zero ? '0' : ' ';
	if (var->flag->zero && !var->flag->minus)
		ft_pfwidpre_preprocess(print + i, var);
	else if (!var->flag->zero && !var->flag->minus)
		ft_pfflag_process(print + i, var);
	return (print);
}

/*
** function of filling precision and converted string
**		 into string print after counting len
** step 1: fill the precision value
** 		a. if spec is 'd i u b o O x X', fill '0'
** 		b. if spec is 's', adjust the len of converted string (ret[LEN_SRC])
** step 2: fill the converted string value
** step 3: run function "ft_pfwidpre_widprocess" if necessary
*/

char	*ft_pfwidpre_preprocess(char *print, t_var *var)
{
	char	*out;
	int		i;

	i = 0;
	out = var->input->out;
	if (SPEC_INT(var->i_spec) || var->c_spec == 'p')
	{
		var->ret[LEN_SRC] -= *out == '-' ? 1 : 0;
		while (i < var->ret[LEN_PRE])
			print[i++] = '0';
	}
	else if (var->c_spec == 's')
	{
		var->ret[LEN_SRC] += var->ret[LEN_PRE];
		var->ret[LEN_PRE] = 0;
	}
	ft_strncpy(print + var->ret[LEN_PRE], \
	out + (SPEC_SIGN(var->i_spec) && *out == '-' ? 1 : 0), var->ret[LEN_SRC]);
	if (var->flag->minus && var->ret[LEN_WID])
		ft_pfwidpre_widprocess(print + i + var->ret[LEN_SRC], var);
	return (print);
}
