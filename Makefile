NAME = push_swap
HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror
CC = 	cc
RM = 	rm -f

LIBFTDIR = 		incl/libft/libft.a
LIBPRINTFDIR = 	incl/printf/libftprintf.a

SRCS = push_swap.c check_input.c  

OBJS = $(SRCS:.c=.o)

all: ${NAME}

%.o: %.c	${HEADER} Makefile
			make -C ${LIBFTDIR}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${INCLUDE}

fclean: clean
		$(RM) $(NAME)

clean:
		$(RM) $(OBJS)
		@cd ${LIBFTDIR} && ${MAKE} clean
		@cd ${LIBPRINTFDIR} && ${MAKE} clean

re: fclean all
.PHONY: all clean fclean re
