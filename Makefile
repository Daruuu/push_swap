
HEADER= push_swap.h
NAME= push_swap.a

CFLAGS= -Wall -Wextra -Werror
CC= cc
RM= rm -f

SRCS=



OBJS= $(SRCS:.c=.o)

all: ${NAME}

%.o : %.c push_swap.h
	${CC} ${CFLAGS} -c $< -o $@


fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
