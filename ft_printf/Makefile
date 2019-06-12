# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chyuen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 11:15:51 by chyuen            #+#    #+#              #
#    Updated: 2019/05/22 13:28:06 by chyuen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

DIRHDER = ./includes/
DIRLIB = ./libft/
DIRSRC = ./srcs/

all: $(NAME)

$(NAME):
	gcc -c $(DIRLIB)*.c $(DIRSRC)*.c -I $(DIRHDER) -Wall -Wextra
	ar rcs $(NAME) *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
