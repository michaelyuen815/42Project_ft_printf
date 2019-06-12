# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chyuen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 19:31:51 by chyuen            #+#    #+#              #
#    Updated: 2019/05/22 19:32:10 by chyuen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

DIRHEAD = ft_printf/includes

all: $(NAME)

$(NAME):
	gcc main.c ft_printf/srcs/*.c -I $(DIRHEAD) -L ft_printf -lftprintf -Wall -Wextra
	./$(NAME)

c: fclean
	gcc test/test_c.c ft_printf/srcs/*.c -I $(DIRHEAD) -L ft_printf -lftprintf -Wall -Wextra
	./$(NAME)
	
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all