/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:53:30 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/11 13:57:29 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// TODO: change name of file!
/*
 * this is function execute after fill the list with the argv
*/

/*
void	print_stack(int argc, char **argv)
{
	t_stack	stack_a;

	stack_a = fill_linked_list (argc, argv);
	t_node	*current = stack_a.first;

	while (current != NULL)
	{
		current->index, current->value
		current = current->next;
		printf("index: [%d] -> value: %d\n", current->index, current->value);
	}
}
*/

void	print_stack(int argc, char **argv)
{
	t_stack	stack_a;
	t_node	*current;

	current = NULL;
	stack_a = fill_linked_list(argc, argv);
	current = stack_a.first;
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
		value = ft_atoi(argv[i]);
		new_node = malloc (sizeof(t_node));
		if (!new_node)
			ft_printf("error fill linked list\n");
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
	set_index_in_stack(&(stack_a.first));
	return (stack_a);
}
