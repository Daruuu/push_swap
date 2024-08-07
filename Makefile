NAME = push_swap
HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror
CC = 	cc
RM = 	rm -f

LIBFTDIR = 		lib/libft
LIBPRINTFDIR = 	lib/libft/printf

SRCS = $(wildcard src/*.c) $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: ${NAME}

%.o: %.c ${HEADER} Makefile
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: $(OBJS)
		make -C ${LIBFTDIR}
		make -C ${LIBPRINTFDIR}
		${CC} ${CFLAGS} ${OBJS} ${LIBFTDIR}/libft.a ${LIBPRINTFDIR}/libftprintf.a -o ${NAME}
clean:
	$(RM) $(OBJS)
	@cd ${LIBFTDIR} && ${MAKE} clean
	@cd ${LIBPRINTFDIR} && ${MAKE} clean

fclean: clean
	$(RM) $(NAME)
	@cd ${LIBFTDIR} && ${MAKE} fclean
	@cd ${LIBPRINTFDIR} && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re
