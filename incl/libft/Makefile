CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

ARC = ar rcs

NAME = libft.a
HEADER = libft.h

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	   	ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	   	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	   	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	   	ft_atoi.c \
		ft_strdup.c ft_calloc.c \
	   	ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_strmapi.c ft_striteri.c \
	   	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

SRCS_PRINTF = ft_printf.c ft_put_ptr.c ft_put_uint_nbr.c ft_putchar_n.c \
			  ft_puthexa_nbr.c ft_putnbr_n.c ft_putstr.c

SOURCES = $(addprefix libft/, $(SRC)) \
		  		$(addprefix printf/, $(SRCS_PRINTF)) 
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c= .d)

# Metodo Implicito
%.o:%.c 	$(HEADER) Makefile
			@echo "He compilado perroooo!!! 😎 $@"
			$(CC) -MMD -c $(CFLAGS) $< -o $@

all: 		$(NAME)

$(NAME): 	$(OBJS) $(HEADER)
			@echo "\nLinking ... $@\n"
			$(ARC) $(NAME) $(OBJS)

clean:
			@rm -rf $(OBJS) $(OBJS) $(DEPS) $(DEPS)
			@printf "removed objects (.o) & deps (.d)!\n"

fclean: 	clean
			@rm -rf $(NAME)
			@printf "Removed libft.a!\n"

re:			fclean all

-include $(DEPS) $(DEPS)

.PHONY: all clean fclean re
