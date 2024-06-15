NAME = push_swap
HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror
CC = 	cc
RM = 	rm -f

LIBFTDIR = 		incl/libft
LIBPRINTFDIR = 	incl/libft/printf

SRCS=	check_input.c validations.c \
		parse_input.c \
		swappers.c \
		ft_split.c \
		push_swap.c

OBJS = $(SRCS:.c=.o)

all: ${NAME}

%.o: %.c ${HEADER} Makefile
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: $(OBJS)
		make -C ${LIBFTDIR}
		make -C ${LIBPRINTFDIR}
		${CC} ${CFLAGS} ${OBJS} ${LIBFTDIR}/libft.a ${LIBPRINTFDIR}/libftprintf.a -o ${NAME}

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)
	@cd ${LIBFTDIR} && ${MAKE} clean
	@cd ${LIBPRINTFDIR} && ${MAKE} clean

re: fclean all

.PHONY: all clean fclean re
