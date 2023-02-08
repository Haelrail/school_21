SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c
SRCS_SERVER_BONUS = server_bonus.c utils_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c utils_bonus.c

HEADER = includes/minitalk.h

HEADER_BONUS = includes/minitalk_bonus.h

INCLUDES = includes/

SERVER_OBJS = ${SRCS_SERVER:%.c=%.o}
CLIENT_OBJS = ${SRCS_CLIENT:%.c=%.o}
SERVER_OBJS_BONUS = ${SRCS_SERVER_BONUS:%.c=%.o}
CLIENT_OBJS_BONUS = ${SRCS_CLIENT_BONUS:%.c=%.o}

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all:	${SERVER} ${CLIENT}

bonus:
		@make SERVER="${SERVER_BONUS}" \
		CLIENT="${CLIENT_BONUS}" \
		SERVER_OBJS="${SERVER_OBJS_BONUS}" \
		CLIENT_OBJS="${CLIENT_OBJS_BONUS}" \
		HEADER="${HEADER_BONUS}" all

%.o : %.c ${HEADER}
	cc ${CFLAGS} -I ${INCLUDES} -c $< -o $@

${SERVER}:	${SERVER_OBJS} ${HEADER}
	cc ${SERVER_OBJS} -o ${SERVER}

${CLIENT}:	${CLIENT_OBJS} ${HEADER}
	cc ${CLIENT_OBJS} -o ${CLIENT}

clean:
	rm -f ${SERVER_OBJS} ${CLIENT_OBJS} ${SERVER_OBJS_BONUS} ${CLIENT_OBJS_BONUS}

fclean: clean
	rm -f ${SERVER} ${CLIENT} ${SERVER_BONUS} ${CLIENT_BONUS}

re:	fclean all
