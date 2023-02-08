# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 17:17:57 by cjoie             #+#    #+#              #
#    Updated: 2022/07/02 14:36:51 by cjoie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c philo_activities.c finish_check.c utils.c
OBJ = ${SRC:.c=.o}
NAME = philo
FLAGS = -Wall -Wextra -Werror
HEAD = philo.h

${NAME}: ${HEAD} ${OBJ}  Makefile
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

.PHONY: all clean fclean re