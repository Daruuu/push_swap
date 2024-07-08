/*
#include "push_swap.h"

void check_all_validations(int ac, char **av)
{
    if (has_invalid_characters(ac, av))
    {
        ft_printf("Error invalid char\n");
        exit(EXIT_FAILURE);
    }
    else if (has_duplicated_numbers(ac, av))
    {
        ft_printf("Error duplicate number\n");
        exit(EXIT_FAILURE);
    }
    else if (if_numbers_are_sorted(ac, av))
    {
        ft_printf("numbers sorted\n");
        exit(EXIT_SUCCESS);
    }
}

void input_check_argc(int ac, char **av)
{
    t_stack *new_stack = NULL;
    char **split_av = NULL;
    int count_split = 0;

    if (ac < 2)
    {
        ft_printf("ac incorrect!\n");
        return;
    }

    if (ac == 2)
    {
        split_av = ft_split(av[1], ' ');
        while (split_av[count_split])
            count_split++;
        
        check_all_validations(count_split, split_av);
        new_stack = init_stack(count_split, split_av);
        free_split(split_av);
    }
    else
    {
        check_all_validations(ac - 1, av + 1);
        new_stack = init_stack(ac - 1, av + 1);
    }

    if (new_stack)
    {
        print_stack(new_stack->head);
        free_stack(new_stack);
    }
}

int is_valid_number(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!ft_isdigit(str[i]))
        return FALSE;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return FALSE;
        i++;
    }
    return TRUE;
}

int has_invalid_characters(int ac, char **av)
{
    for (int i = 0; i < ac; i++)
    {
        if (!is_valid_number(av[i])) return TRUE; }
    return FALSE;
}

int has_duplicated_numbers(int ac, char **av)
{
    for (int i = 0; i < ac; i++)
    {
        for (int j = i + 1; j < ac; j++)
        {
            if (ft_atoi(av[i]) == ft_atoi(av[j]))
                return TRUE;
        }
    }
    return FALSE;
}

int if_numbers_are_sorted(int ac, char **av)
{
    for (int i = 0; i < ac - 1; i++)
    {
        if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
            return FALSE;
    }
    return TRUE;
}

#include <limits.h>
#include <unistd.h>

static void number_out_of_range(long long *result)
{
    if (*result > INT_MAX || *result < INT_MIN)
    {
        write(1, "number out of range", 20);
        exit(EXIT_FAILURE);
    }
}

int ft_atoi(const char *str)
{
    unsigned int i = 0;
    int signo = 1;
    long long result = 0;

    while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signo = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    result *= signo;
    number_out_of_range(&result);
    return ((int)result);
}

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

#include "push_swap.h"

void check_all_validations(int ac, char **av)
{
    if (has_invalid_characters(ac, av))
    {
        ft_printf("Error invalid char\n");
        exit(EXIT_FAILURE);
    }
    else if (has_duplicated_numbers(ac, av))
    {
        ft_printf("Error duplicate number\n");
        exit(EXIT_FAILURE);
    }
    else if (if_numbers_are_sorted(ac, av))
    {
        ft_printf("numbers sorted\n");
        exit(EXIT_SUCCESS);
    }
}

void input_check_argc(int ac, char **av)
{
    t_stack *new_stack = NULL;
    char **split_av = NULL;
    int count_split = 0;

    if (ac < 2)
    {
        ft_printf("ac incorrect!\n");
        return;
    }

    if (ac == 2)
    {
        split_av = ft_split(av[1], ' ');
        while (split_av[count_split])
            count_split++;

        check_all_validations(count_split, split_av);
        new_stack = init_stack(count_split, split_av);
        free_split(split_av);
    }
    else
    {
        check_all_validations(ac - 1, av + 1);
        new_stack = init_stack(ac - 1, av + 1);
    }

    if (new_stack)
    {
        print_stack(new_stack->head);
        free_stack(new_stack);
    }
}

int is_valid_number(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!ft_isdigit(str[i]))
        return FALSE;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return FALSE;
        i++;
    }
    return TRUE;
}

int has_invalid_characters(int ac, char **av)
{
    for (int i = 0; i < ac; i++)
    {
        if (!is_valid_number(av[i]))
            return TRUE;
    }
    return FALSE;
}

int has_duplicated_numbers(int ac, char **av)
{
    for (int i = 0; i < ac; i++)
    {
        for (int j = i + 1; j < ac; j++)
        {
            if (ft_atoi(av[i]) == ft_atoi(av[j]))
                return TRUE;
        }
    }
    return FALSE;
}

int if_numbers_are_sorted(int ac, char **av)
{
    for (int i = 0; i < ac - 1; i++)
    {
        if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
            return FALSE;
    }
    return TRUE;
}
*/
