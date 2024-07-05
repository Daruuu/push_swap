/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:53:30 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/05 14:09:58 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int count_arguments(int ac) {

    int count;
    int i;

    i = 0;
    count = 1;
    while (i < ac)
    {
        count++;
        i++;
    }
    return (i);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av++;
	if (has_invalid_characters(ac - 1, av) || has_duplicated_numbers(ac - 1, av))
    {
		ft_printf("Error\n");
		return (1);
	}
	if (if_numbers_are_sorted(ac - 1, av))
		return (0);
	// call a push_swap here 
	return (0);
}

/*
int main(int ac, char **av)
{
    int     count_ac;
    int     *array_input;
    int     i;

    if (ac == 2)
    {
        ft_printf("call split\n");
    }
    else
    {
        count_ac = count_arguments(ac);
        array_input = malloc(sizeof(*array_input) * count_ac + 1);
        if (!array_input)
        {
            free(array_input);
            return (0);
        }
        //  contamos los ac
        //  creamos un *ptr y lo rellenamos con todo el input
        i = 1;
        ft_printf("count_ac(): %d\n", count_ac);
        ft_printf("array here\n");
        while (i < count_ac)
        {
            array_input[i] = ft_atoi(av[i]);
            ft_printf("arr[%d] : %d\n", i, array_input[i]);
            i++;
        }
        //call print INPUT 
    }
    return (0);
}
*/
/*
int main(int ac, char **av) {
    //int     i;
    int     arg_count;

    arg_count = count_arguments(ac);
    ft_printf("Number of arguments: %d\n", arg_count);
    ft_printf("-----------------------------\n");
    */
    /*
    i = 0;
    while (++i < arg_count)
    {
        printf("argument: [%d] => %d\n", i, ft_atoi(av[i]));
    }
    */
    /*CALL FUNCTIONS FROM PUSH SWAP*/
	//check_all_inputs(ac, av);
	//print_stack(ac, av);
    /*
    return(0);

}
*/
