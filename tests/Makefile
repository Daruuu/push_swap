NAME = push_swap
HEADER = ../push_swap.h

LDFLAGS = -no-pie
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
DEBUG = -g

LIBFTDIR = ../incl/libft
LIBPRINTFDIR = ../incl/libft/printf

SRCS = $(wildcard ../*.c)
OBJS = $(SRCS:.c=.o)

# TESTING VARIABLES
TEST_NAME = test_push_swap
TEST_SRCS = main.c
TEST_OBJS = ${TEST_SRCS:.c=.o}

all: ${NAME}

%.o: %.c ${HEADER} Makefile
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: $(OBJS)
	@make -C ${LIBFTDIR}
	@make -C ${LIBPRINTFDIR}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFTDIR}/libft.a ${LIBPRINTFDIR}/libftprintf.a -o ${NAME} ${LDFLAGS}

test: $(TEST_OBJS) $(OBJS)
	@make -C ${LIBFTDIR}
	@make -C ${LIBPRINTFDIR}
	@${CC} ${CFLAGS} ${TEST_OBJS} ${OBJS} ${LIBFTDIR}/libft.a ${LIBPRINTFDIR}/libftprintf.a -o ${TEST_NAME} ${LDFLAGS}

testgdb: $(TEST_OBJS) $(OBJS)
	@make -C ${LIBFTDIR}
	@make -C ${LIBPRINTFDIR}
	@${CC} ${CFLAGS} ${DEBUG} ${TEST_OBJS} ${OBJS} ${LIBFTDIR}/libft.a ${LIBPRINTFDIR}/libftprintf.a -o ${TEST_NAME} ${LDFLAGS}

c:
	@cd ${LIBFTDIR} && ${MAKE} clean
	@cd ${LIBPRINTFDIR} && ${MAKE} clean
	@$(RM) $(OBJS) $(TEST_OBJS)

fc: clean
	@$(RM) $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test
