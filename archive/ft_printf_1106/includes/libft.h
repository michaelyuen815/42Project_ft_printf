/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:51:49 by chyuen            #+#    #+#             */
/*   Updated: 2019/05/03 10:56:01 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

/*
** Common static value or character checking
*/

# define I_MAX 2147483647
# define I_MIN -2147483648
# define BL_SP(ch) (ch == 32 || (ch > 8 && ch < 14))
# define BL_WSP(ch) (ch == 32 || ch == 9 || ch == 10)
# define BL_UP(ch) (ch > 64 && ch < 91)
# define BL_LW(ch) (ch > 96 && ch < 123)

/*
** Linked list setup
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
****************************** Part 1 - Libc functions **************
**
** Character checking or changing
*/

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** string property checking
*/

size_t			ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** void * functions for:
** setup -- ft_memset,
** cheaning -- ft_bzero,
** copying -- ft_memcpy, ft_memmove, ft_memccpy
** sreaching -- ft_memchr, ft_memcmp
*/

void			ft_bzero(void *s, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			ft_str_skipsp(const char **str);

/*
** String function of searching value or pointer
** for nbr -- ft_atoi
** for char -- ft_strchr, ft_strrchr
** for string -- ft_strstr, ft_strnstr
*/

int				ft_atoi(const char *str);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);

/*
** String function of creating new string by:
** dulipcating -- ft_strdup
** appending -- ft_strcat / ft_strncat / ft_strlcat
** replacing -- ft_strcpy / ft_strncpy
*/

char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t dstsize);

/*
****************************** Part 2 - Additional functions *************
*/

/*
** void* function creation & deletion
*/

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);

/*
** String comparing function
*/

int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

/*
** String creation with allocated memory
** creation -- ft_strnew
** cleaning -- ft_strdel, ft_strclr
** adjusting -- ft_striter, ft_striteri
** creating 1 string with 1 string -- ft_itoa, ft_strrim, ft_strmap, ft_strmapi
** creating 1 string with 2 string -- ft_strjoin
** splitting 1 string - ft_strsplit
*/

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_strsplit(char const *s, char c);

/*
** output function for different file descriptor:
** function with fd, file descriptor parameter fd
** function without fd, standard output (fd = 1)
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
****************************** Part 3 - Bonus part **********************
**
** linked list function with:
** creation -- ft_lstnew
** deletion -- ft_lstdelone, ft_lstdel
** linking -- ft_lstadd
** updating -- ft_lstiter, ft_lstmap
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
****************************** ft_printf part ****************************
*/

int				ft_printf(const char *str, ...);

#endif
