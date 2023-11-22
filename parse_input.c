/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:53:30 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/22 22:33:36 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
 * this is function execute after fill the list with the argv
*/
void	print_stack(int argc, char **argv)
{
	t_stack stack_a;
	stack_a = fill_t_list(argc, argv);

	t_list *current = stack_a.first;
	while (current != NULL)
	{
		printf("index: [%d] -> value: %d\n", current->index, current->value);
		current = current->next;
	}
}

/*
 * funct to fill stack a with argv
*/

t_stack	fill_t_list(int argc, char **argv)
{
	t_stack	stack_a;
	int		i;
	int		value;
	t_list	*new_node;

	stack_a.len = 0;
	stack_a.first = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);/* create a new node for the list */
		new_node = malloc (sizeof(t_list));
		if (!new_node)
			exit(EXIT_FAILURE);
		new_node->value = value;
		new_node->index = i - 1;
		new_node->next = NULL; /*add the node to the front of the list */
		new_node->next = stack_a.first;
		stack_a.first = new_node;
		stack_a.len++;
		i++;
	}
	return (stack_a);
}

int	ft_lst_size(t_list *lst)
{
	size_t	i;

	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
