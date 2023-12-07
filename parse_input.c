/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:53:30 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/07 21:31:16 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
 * this is function execute after fill the list with the argv
*/

void	print_stack(int argc, char **argv)
{
	t_stack	stack_a;

	stack_a = fill_linked_list (argc, argv);
	t_node	*current = stack_a.first;
	while (current != NULL)
	{
		printf("index: [%d] -> value: %d\n", current->index, current->value);
		current = current->next;
	}
}

/*
 * funct to fill stack a with argv
*/
t_stack	fill_linked_list(int argc, char **argv)
{
	t_stack	stack_a;
	int		i;
	int		value;
	t_node	*new_node;

	stack_a.len = 0;
	stack_a.first = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);/* create a new node for the list */
		new_node = malloc (sizeof(t_node));
		if (!new_node)
			write(1, "error fill linked list\n", 23);
			//exit(EXIT_FAILURE);
		new_node->value = value;
		new_node->index = i - 1;
		new_node->next = stack_a.first;
		new_node->previous = NULL;
		if (stack_a.first != NULL)
			stack_a.first->previous = new_node;
		stack_a.first = new_node;
		stack_a.len++;
		i++;
	}
	//sort_stack_ascendent(&stack_a.first);
	return (stack_a);
}
