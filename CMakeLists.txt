cmake_minimum_required(VERSION 3.28)
project(push_swap_clion C)

set(CMAKE_C_STANDARD 11)

add_executable(push_swap_clion
        lib/libft/printf/ft_printf.c
        lib/libft/printf/ft_put_ptr.c
        lib/libft/printf/ft_put_uint_nbr.c
        lib/libft/printf/ft_putchar_n.c
        lib/libft/printf/ft_puthexa_nbr.c
        lib/libft/printf/ft_putnbr_n.c
        lib/libft/printf/ft_putstr.c
        push_swap.h
        push_swap.c
        src/chunks_algorithm.c
        src/diff_sort_options.c
        src/free_and_erros.c
        src/input_check.c
        src/input_validations.c
        src/push_operations.c
        src/rev_rotates_operations.c
        src/rotates_operations.c
        src/stack_aux.c
        src/stack_helper.c
        src/stack_utils.c
        src/swap_operations.c
        lib/libft/ft_atoll.c
        lib/libft/ft_isdigit.c
        lib/libft/ft_split.c
        lib/libft/ft_strlen.c
        lib/libft/ft_strchr.c
        lib/libft/ft_substr.c
        src/functions_no_using.c
)
