/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:59:41 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/27 12:59:44 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_pflst_delone(t_print **t_list)
{
	if (!(*t_list))
		return ;
	if ((*t_list)->len)
		free((*t_list)->len);
	if ((*t_list)->output)
		free((*t_list)->output);
	if ((*t_list)->flag)
		free((*t_list)->flag);
	free(*t_list);
	*t_list = NULL;
}

void		ft_pflst_del(t_print **t_list)
{
	t_print	*tmp;

	if (!(*t_list))
		return ;
	while ((*t_list)->next)
	{
		tmp = (*t_list)->next;
		(*t_list)->next = tmp->next;
		ft_pflst_delone(&tmp);
	}
	ft_pflst_delone(t_list);
}

t_print		*ft_pflst_init(const char **str, char bl_arg, va_list lst_arg)
{
	t_print *ret;

	if (!(ret = (t_print*)malloc(sizeof(t_print))))
		return (NULL);
	ret->next = NULL;
	*str += (**str == '%' ? 1 : 0);
	ret->b_arg = bl_arg;
	ret->flag = ft_pfflag_init(str, bl_arg);
	ret->i_width = (bl_arg ? ft_pflen_widprec_init(str, 0, lst_arg) : -1);
	ret->i_prec = ((bl_arg && **str == '.') ?\
		ft_pflen_widprec_init(str, 1, lst_arg) : -1);
	ret->len = ft_pflen_len_init(str, bl_arg);
	ret->c_spec = (bl_arg ? **str : 's');
	*str += (bl_arg ? 1 : 0);
	if (ft_pfvar_init(ret, str, lst_arg))
		return (ret);
	ft_pflst_delone(&ret);
	return (NULL);
}

int			ft_pflst_len(const char *str, t_print *t_list, int *len)
{
	int		ret;
	int		int_flag;

	if (ft_strchr("%Cc", t_list->c_spec))
		ret = -1;
	else if (ft_strchr("s", t_list->c_spec))
		ret = (t_list->i_prec >= *len ? -1 : t_list->i_prec);
	else if (ft_strchr("pdiuUboOxX", t_list->c_spec))
	{
		*len -= (*str == '-' ? 1 : 0);
		ret = (t_list->i_prec <= *len ? -1 : t_list->i_prec);
		*len += (*str == '-' ? 1 : 0);
		ret += (ret != -1 && *str == '-' ? 1 : 0);
		ret = (!t_list->i_prec && ft_strequ(str, "0")) ? 0 : ret;
	}
	else
		return (-1);
	if ((int_flag = ft_pfflag_len(str, t_list)))
		ret = (ret == -1 ? *len : ret) + int_flag;
	*len = (ret == -1 ? *len : ret);
	ret = (t_list->i_width <= *len ? ret : t_list->i_width);
	return (ret);
}

int			ft_pflst_output(t_print *t_list)
{
	int		len;
	int		len_ext;
	char	*ret_ext;
	char	*ret;

	ret = ft_pfvar_output(t_list);
	len = (ft_strchr("cC", t_list->c_spec) ? 1 : ft_strlen(ret));
	t_list->output->ld = 0;
	t_list->output->s_out = ret;
	if ((len_ext = ft_pflst_len(ret, t_list, &len)) >= 0)
	{
		ret_ext = ft_strnew(len_ext);
		ret_ext = t_list->flag->minus || t_list->flag->zero ? \
			ft_pfflag_process(ret_ext, t_list, len_ext, len) : \
			ft_pflen_wid_process(ret_ext, t_list, len_ext, len);
		ft_strdel(&ret);
		t_list->output->s_out = ret_ext;
		len = len_ext;
	}
	return (len);
}
