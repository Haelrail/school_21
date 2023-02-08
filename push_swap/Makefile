# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 20:16:32 by cjoie             #+#    #+#              #
#    Updated: 2022/03/19 17:07:33 by cjoie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = atoi.c checkers.c find_extremum.c lib_func_1.c lib_func_2.c \
		lst_change.c main.c move_amount.c push.c put_at_place.c \
		rev_rotate.c rotate.c small_sort.c swap.c lst_clear.c
OBJ = ${SRC:.c=.o}
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
HEAD = push_swap.h

${NAME}: ${HEAD} ${OBJ}
		gcc $(FLAGS) ${OBJ} -I $(HEAD) -o ${NAME}

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