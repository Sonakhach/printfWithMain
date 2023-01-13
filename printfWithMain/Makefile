NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
