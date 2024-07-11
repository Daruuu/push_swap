/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:05:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/11 13:34:10 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    //t_stack *stack_b;

    stack_a = NULL; 
    //stack_b = NULL; 
    if (ac < 2)
        return(0);
    input_check_argc(ac, av);
    stack_a = init_stack(ac, av);
    //handle_sort_options(stack_a, stack_a->len, stack_b);
    //ft_printf("initial stack lenght: %d\n", stack_a->len);
    handle_sort_options(&stack_a, stack_a->len);
    //print_stack(stack_a);
    //free(stack_a);
    return (0);
}
