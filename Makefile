NAME = get_next_line.a

CC = cc

CME = ar -rcs 

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRCS = get_next_line.c \
get_next_line_utils.c \
main.c
                     
OBJS = $(SRCS:.c=.o)

${NAME}:	${OBJS}
			${CME} ${NAME} ${OBJS}

all:		${NAME}

clean:
			rm -f *.o *.out

fclean:		clean
			rm -f ${NAME}

re:			fclean all

compile:	re
	cc *.c

run:	compile
	./a.out