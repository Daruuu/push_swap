
HEADER= push_swap.h
NAME= push_swap

CFLAGS= -Wall -Wextra -Werror
CC= cc
RM= rm -f
INCL= src_libft/

SRCS= push_swap.c push_swap.h

OBJS= $(SRCS:.c=.o)

all: ${NAME}

%.o : %.c push_swap.h Makefile
	${CC} ${CFLAGS} -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
