# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 02:43:51 by dasalaza          #+#    #+#              #
#    Updated: 2023/11/19 03:11:18 by dasalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
LIBFTDIR = srcs/src_libft/

SRCS = push_swap.c 

OBJS = $(SRCS:.c=.o)
INCLUDE = -L ./libft -libft.a

all: ${NAME}

%.o : %.c ${HEADER} Makefile
	make -C ${LIBFTDIR}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${INCLUDE}

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)
	@cd ${LIBFTDIR} && ${MAKE} clean

re: fclean all

.PHONY: all clean fclean re
