# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 19:27:10 by cjoie             #+#    #+#              #
#    Updated: 2022/01/09 19:27:12 by cjoie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_prints.c ft_printhex.c src.c
OBJ = ${SRC:.c=.o}
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
HEAD = ft_printf.h

${NAME}: ${OBJ}
		ar rcs ${NAME} ${OBJ}

%.o   : %.c ${HEAD}
		gcc $(FLAGS) -c $< -o $@

all:
		make ${NAME}

clean:
		rm -f ${OBJ}
		
fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re