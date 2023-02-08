# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/30 02:23:19 by cjoie             #+#    #+#              #
#    Updated: 2022/06/07 23:06:05 by cjoie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_data.c put_line.c draw_map.c main.c
OBJ = ${SRC:.c=.o}
NAME = fdf
FLAGS = -Wall -Wextra -Werror
HEAD = fdf.h
MLX_DIR = ./minilibx_macos
MLX_FLAGS = -L ${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
${NAME}: relinc

relinc	:
		make -C ./libft
		make -C ${MLX_DIR}
		make ${OBJ}
		gcc ${FLAGS} ${OBJ} -I ${HEAD} -L ./libft -lft -lm ${MLX_FLAGS} -o ${NAME}

%.o   : %.c ${HEAD}
		gcc ${FLAGS} -I ${MLX_DIR} -c $< -o $@

all:
		make ${NAME}

clean:
		make clean -C ./libft
		make clean -C ${MLX_DIR}
		rm -rf ${OBJ}
		
fclean: clean
		make fclean -C ./libft
		make clean -C ${MLX_DIR}
		rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re relinc