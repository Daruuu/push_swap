cmake_minimum_required(VERSION 3.28)
project(push_swap_clion C)

set(CMAKE_C_STANDARD 11)

add_executable(push_swap_clion
        tests/main.c
        push_swap.h
        incl/libft/printf/ft_printf.c
        incl/libft/printf/ft_put_ptr.c
        incl/libft/printf/ft_put_uint_nbr.c
        incl/libft/printf/ft_putchar_n.c
        incl/libft/printf/ft_puthexa_nbr.c
        incl/libft/printf/ft_putnbr_n.c
        incl/libft/printf/ft_putstr.c
        swap_operations.c
        stack_utils.c
        rotates_operations.c
        rev_rotates_operations.c
        push_swap.c
        push_operations.c
        no_use.c
        input_validations.c
        input_check.c
        ft_split.c
        free_and_erros.c
        incl/libft/ft_strlen.c
        incl/libft/ft_strchr.c
        incl/libft/ft_substr.c
        chunks_algorithm.c
        stack_helper.c
        stack_aux.c)
