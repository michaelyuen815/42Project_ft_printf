/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:25:32 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/05 11:25:36 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <unistd.h>
#include <string.h>

static int ft_strcheck(const char *s1, const char *s2, int n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 || *s2)
		return (0);
	return (1);
}

int ft_function(int i, int case_j)
{
	switch (case_j)
	{
		case 0: 
			return (!i ? ft_printf("Hello world!") : printf("Hello world!"));
		case 1: 
			return (!i ? ft_printf("") : printf(" "));
		case 2: 
			return (!i ? ft_printf("| |") : printf("| |"));
		case 3:
			return (!i ? ft_printf("|\n|") : printf("|\n|"));
		case 4:
			return (!i ? ft_printf("test") : printf("test"));
		default : 
			return (0);
	}
}

void ft_testcomp(void)
{
	int	int_ret[2];
	char ret[2][4096];
	int	i;
	int j;
	int	fd_bk;
	int	pipefd[2];

	j = -1;
	pipe(pipefd);
	while (++j < 5)
	{
		i = -1;
		fd_bk = dup(fileno(stdout));
		dup2(pipefd[1], fileno(stdout));
		while (++i < 2)
		{
			int_ret[i] = ft_function(i, j);
			fflush(stdout);
			close(pipefd[1]);
			read(pipefd[0], ret[i], 4096);
			if (int_ret[i] != -1)
				ret[i][int_ret[i]] = 0;
		}
		dup2(fd_bk, fileno(stdout));
		if (int_ret[0] == int_ret[1] && ft_strcheck(ret[0], ret[1], int_ret[1]))
			printf("Case %d: OK\n", j);
		else
			printf("Case %d: fail with |%s|\n", j, ret[1]);
	}
}

int main(void)
{
	ft_testcomp();
	return (0);
}