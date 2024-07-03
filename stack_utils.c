/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:57:52 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/03 12:05:13 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_stack(t_stack *stack)
{
	int		i;
	t_node	*current_node;

	current_node = stack->head;
	i = 0;
	while (current_node != NULL)
	{
		i++;
		current_node = current_node->next;
	}
	stack->len = i;
	return (i);
}

/*
 * iterate through stack
*/
void	print_stack(t_node *stack)
{
	t_node	*current;
	int		i;

	if (!stack)
		return ;
	current = stack;
	i = 0;
	while (current != NULL)
	{
		printf("[%d]->%d\n", i, current->data);
		i++;
		current = current->next;
	}
}

/* Set indexes in STACK*/
//TODO: redo this functions with others variables names
void	set_index_stack(t_node **head_ref)
{
	t_node	*current;
	t_node	*others;
	int		new_index;

	current = *head_ref;
	others = current;
	while (current)
	{
		new_index = 0;
		while (others)
		{
			if (others->data < current->data)
				new_index ++;
			others = others->next;
		}
		current->index = new_index;
		others = *head_ref;
		current = current->next;
	}
}

/*
 * function if input list are sorted,
 * finish the program 
*/

int	stack_is_sorted(t_stack *stack_a)
{
	t_node	*current;

	if (stack_a == NULL || stack_a->head == NULL)
		return (EXIT_FAILURE);
	current = stack_a->head;
	while (current != NULL)
	{
		if (current->data > current->next->data)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
