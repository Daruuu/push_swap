NAME = push_swap
HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror
CC = 	cc
RM = 	rm -f

LIBFTDIR = 		incl/libft/libft.a
LIBPRINTFDIR = 	incl/printf/libftprintf.a

SRCS = check_input.c fill_linked_list.c \ 

OBJS = $(SRCS:.c=.o)

all: ${NAME}

%.o: %.c	${HEADER} Makefile
			make -C ${LIBFTDIR}
			make -C ${LIBPRINTFDIR}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${INCLUDE}

fclean: clean
		$(RM) $(NAME)
clean:
		$(RM) $(OBJS)
		@cd ${LIBFTDIR} && ${MAKE} clean
		@cd ${LIBPRINTFDIR} && ${MAKE} clean

re: fclean all
.PHONY: all clean fclean re
