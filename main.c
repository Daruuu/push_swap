/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:11:47 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/22 20:29:08 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

/*
 * example input:
 * CASE 1:
 * ./push_swap 1 3 5 6 7
 *
 * CASE 2:
 * ARG="4 1 9 2"./push_swap $ARG | wc -l
*/

int main(int argc, char **argv)
{
	check_all_input(argc, argv);
	print_stack(argc, argv);

    return (0);
}
/*
    t_stack stack_a;
	stack_a = fill_t_list(argc, argv);

    t_list *current = stack_a.first;
    while (current != NULL)
    {
        printf("Index: %d -> value: [%d]\n", current->index, current->value);
        current = current->next;
    }
*/
