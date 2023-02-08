# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoie <cjoie@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 18:02:29 by cjoie             #+#    #+#              #
#    Updated: 2022/11/10 18:02:31 by cjoie            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minishell

MAIN			=	minishell.c
SHLL_FOLDER		=	./main/
SHLL_FILE		=	destructor.c						\
					executor.c		exec_bin.c			\
									exec_cmd.c			\
									exec_dup.c			\
									exec_pipe.c			\
									exec_prcs.c			\
					readline.c							\
					errors.c							\
					initializer.c	init_sh_lvl.c		\
					parser.c		parse_findword_1.c	\
									parse_findword_2.c	\
									parse_redirect.c	\
					signal.c
SHLL			=	$(addprefix $(SHLL_FOLDER), $(SHLL_FILE))

BLTN_FOLDER		=	./builtins/
BLTN_FILES		=	cd.c		\
					cd_utils.c	\
					echo.c		\
					env.c		\
					exit.c		\
					export.c	\
					pwd.c		\
					unset.c
BLTN			=	$(addprefix $(BLTN_FOLDER), $(BLTN_FILES))

UTLS_FOLDER		=	./utils/
UTLS_FILE		=	ft_atoi.c			ft_split_free.c		\
					ft_atoll.c			ft_split_halve.c	\
					ft_bzero.c			ft_split_len.c		\
					ft_calloc.c			ft_strchr.c			\
					ft_isalpha.c		ft_strcmp.c			\
					ft_isdigit.c		ft_strdup.c			\
					ft_isnumber.c		ft_strfree.c		\
					ft_isspace.c		ft_strjoin.c		\
					ft_issymbol.c		ft_strlcat.c		\
					ft_mod.c			ft_strlcpy.c		\
					ft_strcpy.c			ft_strlen.c			\
					ft_putchar_fd.c		ft_split.c			\
					ft_putendl_fd.c		ft_strncmp.c		\
					ft_putnbr_fd.c		ft_strndup.c		\
					ft_putsplit_fd.c	ft_substr.c			\
					ft_putstr_fd.c		ft_wrdcmp.c			\
					ft_itoa.c								\
					ft_realloc.c		ft_realloc_double.c

UTLS			=	$(addprefix $(UTLS_FOLDER), $(UTLS_FILE))

LST_FOLDER		=	./list/
LST_FILE		=	cmd_constr_destr.c		\
					cmd_methods.c			\
					lst_methods.c			\
					lst_methods_add.c		\
					lst_constr_destr.c
LST				=	$(addprefix $(LST_FOLDER), $(LST_FILE))

SRC				=	$(MAIN)		\
					$(SHLL)		\
					$(BLTN)		\
					$(UTLS)		\
					$(LST)
OBJ				=	$(SRC:.c=.o)

HDR_FOLDER		=	./includes/
HDR_FILE		=	minishell.h
HDR				=	$(addprefix $(HDR_FOLDER), $(HDR_FILE))

СC				=	gcc
FLAG			=	-MMD -g -Wall -Wextra -Werror

HOMEBREW_PREFIX	:=	$(shell test -n "$$(which brew)" \
						&& brew config | grep HOMEBREW_PREFIX | cut -d' ' -f2)

INCLUDE_SYS		=	$(HOMEBREW_PREFIX)/opt/readline/include
LIB_SYS			=	$(HOMEBREW_PREFIX)/opt/readline/lib

all		:	$(NAME)

%.o		:	%.c $(HDR) Makefile
			$(CC) -c $< -o $@ -I $(HDR_FOLDER)		\
			-I$(LIB_SYS) -I$(INCLUDE_SYS)

$(NAME)	:	$(OBJ) $(HDR) Makefile
			$(CC) $(OBJ) $(FLAG) -I $(HDR_FOLDER)	\
			-o $(NAME) -lreadline -L$(LIB_SYS)

clean	:
			rm -f $(OBJ)
			rm -f .here_doc

fclean	:	clean
			rm -f $(NAME)

re		:	fclean
			make all

.PHONY	:	all clean fclean re