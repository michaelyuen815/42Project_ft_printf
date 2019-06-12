/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:56:17 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/07 14:56:22 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("test case |%%c|\n");
	ft_printf("|%c|", 0);
	printf("\nexp ret = ");
	printf("|%c|", 0);
	printf("\n\n");

	printf("test case |%%c|\n");
	ft_printf("|%c|", 65);
	printf("\nexp ret = ");
	printf("|%c|", 65);
	printf("\n\n");

	printf("test case |%%+c|\n");
	ft_printf("|%+c|", 65);
	printf("\nexp ret = ");
	printf("|%+c|", 65);
	printf("\n\n");

	printf("test case |%%-c|\n");
	ft_printf("|%-c|", 65);
	printf("\nexp ret = ");
	printf("|%-c|", 65);
	printf("\n\n");

	printf("test case |%% c|\n");
	ft_printf("|% c|", 65);
	printf("\nexp ret = ");
	printf("|% c|", 65);
	printf("\n\n");

	printf("test case |%%#c|\n");
	ft_printf("|%#c|", 65);
	printf("\nexp ret = ");
	printf("|%#c|", 65);
	printf("\n\n");

	printf("test case |%%0c|\n");
	ft_printf("|%0c|", 65);
	printf("\nexp ret = ");
	printf("|%0c|", 65);
	printf("\n\n");

	printf("test case |%%hhc|\n");
	ft_printf("|%hhc|", 65);
	printf("\nexp ret = ");
	printf("|%hhc|", 65);
	printf("\n\n");

	printf("test case |%%hc|\n");
	ft_printf("|%hc|", 65);
	printf("\nexp ret = ");
	printf("|%hc|", 65);
	printf("\n\n");

	printf("test case |%%lc|\n");
	ft_printf("|%lc|", 65);
	printf("\nexp ret = ");
	printf("|%lc|", 65);
	printf("\n\n");

	printf("test case |%%llc|\n");
	ft_printf("|%lc|", 65);
	printf("\nexp ret = ");
	printf("|%llc|", 65);
	printf("\n\n");

	printf("test case |%%10c|\n");
	ft_printf("|%10c|", 65);
	printf("\nexp ret = ");
	printf("|%10c|", 65);
	printf("\n\n");

	printf("test case |%%010c|\n");
	ft_printf("|%010c|", 65);
	printf("\nexp ret = ");
	printf("|%010c|", 65);
	printf("\n\n");

	printf("test case |%%-10c|\n");
	ft_printf("|%-10c|", 65);
	printf("\nexp ret = ");
	printf("|%-10c|", 65);
	printf("\n\n");

	printf("test case |%%#10c|\n");
	ft_printf("|%#10c|", 65);
	printf("\nexp ret = ");
	printf("|%#10c|", 65);
	printf("\n\n");

	return (0);
}