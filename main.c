/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 10:45:22 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/22 10:46:26 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

void test_printf_check(t_var *t_list)
{
	size_t i;

	i = 0;
	while (t_list)
	{
		printf("\n%zuth node in this printing:\n", i);
		printf("flag control:\n-: %d\n+: %d\n( ): %d\n#: %d\n0: %d\n",\
			t_list->flag->minus, t_list->flag->plus, t_list->flag->space,\
			t_list->flag->hash, t_list->flag->zero);
		printf("width control: %d\nprec control: %d\nlength control: %s\n",\
			t_list->i_width, t_list->i_prec, (char*)t_list->len);
		printf("spec flag = |%c|\n", t_list->c_spec);
		//printf("saved data = |%d|\n", t_list->output->i);
		//t_list = t_list->next;
		i++;
	}
}

void print_bits(int nbr)
{
	int i = 32;
	printf("%d : ", nbr);
	while (i--)
		printf("%d", (int)(nbr >> i & 1));
	printf("\n");
}

int main(void)
{
	ft_printf("Hello World!\n");

	return (0);
}

/*
int				main(void)
{
	int			i = 2147483647;
	long		l = 2147483647;
	long long	ll = 9223372036854775807;
	char		c = 0;
	intmax_t	im = 9223372036854775807;

	//while ((double)time / CLOCKS_PER_SEC < 15)
	//{
		ft_printf("\n");
		ft_printf("%%\n");
		ft_printf("%d\n", 42);
		ft_printf("%d%d\n", 42, 41);
		ft_printf("%d%d%d\n", 42, 43, 44);
		ft_printf("%ld\n", l);
		ft_printf("%lld\n", ll);
		ft_printf("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
		ft_printf("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
		ft_printf("%jd %zd %u %o %#08x\n", im, (size_t)i, i, 40, 42);
		ft_printf("%x %#X %S %s%s\n", 1000, 1000, L"ݗݜशব", "test", "test2");
		ft_printf("%s%s%s\n", "test", "test", "test");
		ft_printf("%C\n", 15000);
	//}
	return (0);
}*/