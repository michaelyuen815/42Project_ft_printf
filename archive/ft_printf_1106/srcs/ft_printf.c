/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:31:23 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/22 14:32:02 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** int printf ( const char * format, ... );
** prototype: %[flags][width][.precision][length]specifier
** flags option: #0-+ and space
** width parameter
** specifier % (print %)
** specifier c(char), s(string), p(ptr) with length option l
** specifier d, i(int), o(oct), u(unsigned int),
** 		xX (hex) with length option hh, h, l , ll
** specifier f with length option l, L
** bonus specifier e, g
** bonus flags: *, $, '
** bonus specifier b(binary), r(non-printable char), k(date with ISO format)
*/

static int		ft_printf_pnprint(t_print *t_list)
{
	int cur_ret;
	int	ret;

	ret = 0;
	while (t_list)
	{
		if (t_list->b_arg)
			cur_ret = ft_pflst_output(t_list);
		else
			cur_ret = ft_strlen(t_list->output->s_out);
		write(1, t_list->output->s_out, cur_ret);
		free(t_list->output->s_out);
		ret += cur_ret;
		t_list = t_list->next;
	}
	return (ret);
}

static t_print	*ft_printf_lst_main(const char **str, va_list lst_arg)
{
	t_print	*t_list;
	t_print *t_lstcur;

	t_list = ft_pflst_init(str, **str == '%', lst_arg);
	t_lstcur = t_list;
	while (**str && t_lstcur)
	{
		if (!(t_lstcur->next = \
		ft_pflst_init(str, **str == '%', lst_arg)))
			break ;
		t_lstcur = t_lstcur->next;
	}
	if (**str || t_lstcur == NULL)
		ft_pflst_del(&t_list);
	return (t_list);
}

int				ft_printf(const char *arg, ...)
{
	t_print		*t_list;
	int			ret;
	const char	*str;
	va_list		lst_arg;

	va_start(lst_arg, arg);
	str = arg;
	ret = 0;
	if (str)
	{
		t_list = ft_printf_lst_main(&str, lst_arg);
		ret = (t_list ? ft_printf_pnprint(t_list) : -1);
		ft_pflst_del(&t_list);
	}
	va_end(lst_arg);
	return (ret);
}
