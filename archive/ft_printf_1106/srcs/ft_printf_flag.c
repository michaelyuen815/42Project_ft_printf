/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:32:15 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/27 16:32:26 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		*ft_pfflag_init(const char **str, char bl_arg)
{
	t_flag *ret;

	if (!(ret = (t_flag*)malloc(sizeof(t_flag))))
		return (NULL);
	ret->minus = 0;
	ret->plus = 0;
	ret->space = 0;
	ret->hash = 0;
	ret->zero = 0;
	if (bl_arg)
	{
		while (ft_strchr(FLAG, **str))
		{
			ret->minus |= **str == '-';
			ret->plus |= **str == '+';
			ret->space |= **str == ' ';
			ret->hash |= **str == '#';
			ret->zero |= **str == '0';
			(*str)++;
		}
	}
	return (ret);
}

static int	ft_pfflag_ctrl(t_print *t_list)
{
	if (!ft_strchr("difeg", t_list->c_spec))
		t_list->flag->plus = 0;
	if (!ft_strchr("difeg", t_list->c_spec))
		t_list->flag->space = 0;
	if (!ft_strchr("oxXfeg", t_list->c_spec))
		t_list->flag->hash = 0;
	if (ft_strchr("%sp", t_list->c_spec))
		t_list->flag->zero = 0;
	if (t_list->flag->plus && t_list->flag->space)
		t_list->flag->space = 0;
	if (t_list->flag->minus && t_list->flag->zero)
		t_list->flag->zero = 0;
	return (1);
}

int			ft_pfflag_check(t_print *t_list)
{
	if (t_list->i_prec != -1)
		t_list->flag->zero = 0;
	if (BL_FLAG_CHECK)
	{
		if (ft_strchr("%Ccsp", t_list->c_spec))
			return (!(t_list->flag->plus || t_list->flag->space || \
				t_list->flag->hash || t_list->flag->zero));
		else if (ft_strchr("di", t_list->c_spec))
			return (!t_list->flag->hash);
		else if (ft_strchr("buU", t_list->c_spec))
			return (!(t_list->flag->plus || t_list->flag->space || \
				t_list->flag->hash));
		else if (ft_strchr("oxXfeg", t_list->c_spec))
			return (!(t_list->flag->plus || t_list->flag->space));
		else
			return (!ft_printf("missing flag control for spec %c\n",\
					t_list->c_spec));
	}
	else
		return (ft_pfflag_ctrl(t_list));
}

int			ft_pfflag_len(const char *str, t_print *t_list)
{
	int		base;

	ft_pfvar_size(t_list, NULL, &base);
	if ((t_list->flag->plus || t_list->flag->space) && ft_isdigit(*str))
		return (1);
	else if (t_list->flag->hash && base == 3)
		return (1);
	else if (((t_list->flag->hash && !ft_strequ(str, "0")) || \
		t_list->c_spec == 'p') && base == 4)
		return (2);
	return (0);
}

char		*ft_pfflag_process(char *ret, t_print *t_list, int len_ext, int len)
{
	int		i;
	int		base;
	char	*src;

	src = t_list->output->s_out;
	ft_pfvar_size(t_list, NULL, &base);
	i = 0;
	if ((t_list->flag->space || t_list->flag->plus) && ft_isdigit(*src))
		ret[i++] = t_list->flag->space ? ' ' : '+';
	else if (t_list->flag->hash && base == 3)
		ret[i++] = '0';
	else if (((t_list->flag->hash && !ft_strequ("0", src)) || \
		t_list->c_spec == 'p') && base == 4)
	{
		ft_strcpy(ret, (BL_UP(t_list->c_spec) ? "0X" : "0x"));
		i += 2;
	}
	else if (ft_strchr("difeg", t_list->c_spec) && *src == '-')
		ret[i++] = '-';
	if (t_list->flag->zero)
		ft_pflen_wid_process(ret + i, t_list, len_ext - i, len - i);
	else
		ft_pflen_prec_process(ret + i, t_list, len_ext - i, len - i);
	return (ret);
}
