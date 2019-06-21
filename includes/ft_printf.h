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
# define SPEC "%cspdDiuUboOxXfFeEgG"
# define SPEC_END 10
# define SPEC_SIGN(nbr) (nbr == 2 || SPEC_DEC(nbr))
# define SPEC_INT(nbr) (nbr >= 2 && nbr <= 6)
# define SPEC_DEC(nbr) (nbr >= 7 && nbr <= 9)
# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"
# define BUFF_SIZE 100000
# define B_MAX 64
# define BT_MAX 0x0FFFFFFFFFFFFFFFF

# define LEN_SRC 0
# define LEN_FLAG 1
# define LEN_WID 2
# define LEN_PRE 3

typedef struct s_var			t_var;
typedef struct s_flag			t_flag;
typedef enum e_len				t_len;
typedef union u_input			t_input;
typedef struct s_spec			t_spec;
typedef long long int			t_lli;
typedef unsigned long long int	t_ulli;
typedef long double				t_ld;

struct	s_var
{
	t_len	*len;
	t_input	*input;
	int		i_width;
	int		i_prec;
	int		ret[4];
	t_flag	*flag;
	size_t	i_spec;
	char	c_spec;
	char	base;
	char	size;
};

struct	s_flag
{
	char	minus;
	char	plus;
	char	space;
	char	hash;
	char	zero;
	char	decimal;
};

struct	s_spec
{
	char	*spec;
	int		bitsize;
	int		base;
	char	*(*pro)(t_var *var);
};

enum	e_len
{
	none,
	hh = 1,
	h = 2,
	l = 8,
	ll = 8,
	j = 8,
	z = 99,
	L = 15
};

union	u_input
{
	int		i;
	t_lli	lli;
	t_ulli	ulli;
	void	*v;
	t_ld	ld;
	char	*out;
};

int		ft_pfmain_str(char *print, const char **str);

t_flag	*ft_pfflag_init(t_var *var, const char **str);
void	ft_pfflag_ctrl(t_var *var);
int		ft_pfflag_len(t_var *var);
char	*ft_pfflag_process(char *print, t_var *var);

t_len	*ft_pflen_init(t_var *var, const char **str);
void	ft_pflen_ctrl(t_var *var);
t_ld	ft_pflen_divi(int digit);

int		ft_pfvar_size(t_var *var);
void	ft_pfvar_init(t_var *var, va_list lst_arg);
int		ft_pfvar_cal(t_var *var);

int		ft_pfwidpre_init(\
		t_var *var, const char **str, char bl_prec, va_list lst_arg);
int		ft_pfwidpre_len(t_var *var);
char	*ft_pfwidpre_widprocess(char *print, t_var *var);
char	*ft_pfwidpre_preprocess(char *print, t_var *var);

char	*ft_pffunc_box(t_var *var);
char	*ft_pffunc_char(t_var *var);
char	*ft_pffunc_ptr(t_var *var);
char	*ft_pffunc_diu(t_var *var);
char	*ft_funcf_feg(t_var *var);

#endif
