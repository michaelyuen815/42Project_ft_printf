/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:57:53 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/11 16:57:56 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# define FLAG "-+0 #'"
# define SPEC "%CcspdiuUboOxXfeg"
# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"
# define BUFF_SIZE 1000000
# define BITS_MAX 64
# define BITS_MAX_TOL 0xFFFFFFFFFFFFFFFF

typedef struct s_var	t_var;
typedef struct s_flag	t_flag;
typedef enum e_len		t_len;

struct					s_var
{
	t_len			*len;
	//t_output		*output;
	int				i_width;
	int				i_prec;
	t_flag			*flag;
	char			c_spec;
};

struct					s_flag
{
	char	minus;
	char	plus;
	char	space;
	char	hash;
	char	zero;
	char	Decimal;
};

struct					s_spec
{
	char	*spec;
	char	bitsize;
	char	base;
	char	*(*f)(t_var *var);
};

enum						e_len
{
	none,
	hh = 1,
	h = 2,
	l = 8,
	ll = 8,
	j = 8,
	L = 10
};

int ft_pfmain_str(char *print, const char *str, va_list lst_arg);
#endif