/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:23:36 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/22 17:23:58 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "libft.h"

# define FLAG "-+0 #"
# define SPEC "%CcspdiuUboOxXfeg"
# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"
# define BITS_MAX 64
# define BITS_MAX_TOL 18446744073709551615U
# define BL_FLAG_CHECK 0

typedef struct s_print		t_print;
typedef struct s_flag		t_flag;
typedef enum e_len			t_len;
typedef union u_output		t_output;
typedef struct s_spec		t_spec;

struct						s_print
{
	t_print			*next;
	t_len			*len;
	t_output		*output;
	int				i_width;
	int				i_prec;
	t_flag			*flag;
	char			c_spec;
	char			b_arg;
};

struct						s_flag
{
	char	minus;
	char	plus;
	char	space;
	char	hash;
	char	zero;
};

/*
*********Reference***********************
** s, p		>> 	8	ptr
** c, d, i	>>	4	int
** hhi, hhd	>>	1	signed char
** hi, hhd	>>	2	short int
** li 		>>	8	long int
** lli		>>	8	long long int
**
** u		>>	4	unsigned int
** *print p	>>  4	unsigned int
** uoxX		>>	4	unsigned int
** hh uoxX	>>	1	unsigned char
** h uoxX	>>	2	usnigned short int
** l uoxX	>>	8	unsigned long int
** ll uoxX	>>	8	unsigned long long int
** f		>>	8	double
** Lf		>>	16	long double
*/

enum						e_len
{
	none,
	hh = 1,
	h = 2,
	l = 8,
	ll = 8,
	j = 8,
	L = 18
};

union						u_output
{
	int						i;
	long long int			lli;
	unsigned long long int	ulli;
	double					dbl;
	void					*v;
	char					*s_out;
	long double				ld;
};

struct						s_spec
{
	char	*spec;
	char	bitsize;
	char	base;
	char	*(*f)(t_print *t_list);
};

void						ft_pflst_del(t_print **t_list);
t_print						*ft_pflst_init(\
			const char **str, \
			char bl_arg, \
			va_list lst_arg);
int							ft_pflst_output(t_print *t_list);

t_flag						*ft_pfflag_init(const char **str, char bl_arg);
int							ft_pfflag_check(t_print *t_list);
int							ft_pfflag_len(const char *str, t_print *t_list);
char						*ft_pfflag_process(\
			char *ret, \
			t_print *t_list, \
			int len_ext, \
			int len);

int							ft_pflen_widprec_init(\
			const char **str, \
			char bl_prec, \
			va_list lst_arg);
t_len						*ft_pflen_len_init(const char **str, char bl_arg);
char						*ft_pflen_prec_process(\
			char *ret, \
			t_print *t_list, \
			int len_ext, \
			int len);
char						*ft_pflen_wid_process (\
			char *ret, \
			t_print *t_list, \
			int len_ext, \
			int len);

int							ft_pfvar_init(\
			t_print *t_list, \
			const char **str, \
			va_list lst_arg);
int							ft_pfvar_size(\
			t_print *t_list, \
			int *size, \
			int *base);
char		*ft_pfvar_output(t_print *t_list);


char						*ft_pffunc_boxx(t_print *t_list);
char						*ft_pffunc_diu(t_print *t_list);
char						*ft_pffunc_char(t_print *t_list);
char						*ft_pffunc_ptr(t_print *t_list);
char						*ft_funcf_float(t_print *t_list);

#endif
