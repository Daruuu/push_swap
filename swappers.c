/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:01:03 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/03 02:58:27 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * function to order stack in order of value
 * TODO: function to remake with other way
*/

void	sort_stack_by_number(t_node **head_ref)
{
	t_node	*sort_stack;
	t_node	*current_node;
	t_node	*next_node;
	t_node	*temp;

	sort_stack = NULL;
	current_node = *head_ref;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		if (sort_stack == NULL || sort_stack->index > current_node->index)
		{
			current_node->next = sort_stack;
			current_node->previous = NULL;
			if (sort_stack != NULL)
				sort_stack->previous = next_node;
			sort_stack = current_node;
		}
		else
		{
			temp = sort_stack;
			while (temp->next != NULL && temp->next->index < current_node->index)
				temp = temp->next;
			current_node->next = temp->next;
			if (temp->next != NULL)
				temp->next->previous = current_node;
			temp->next = current_node;
			current_node->previous = temp;
		}
		current_node= next_node;
	}
	*head_ref = sort_stack;
}

void	ft_swap (int *a, int *b)
{
	int	*tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

void	swap_nodes (t_node *node_a, t_node *node_b)
{
	int	tempValue;
	int	tempIndex;

	tempValue = node_a->value;
	tempIndex = node_a->index;
	node_a->index = node_b->index;
	node_a->value = node_b->value;
	node_b->index = tempIndex;
	node_b->value = tempValue;
}

/*
 * function if input ist are sorted, finish the program 
*/

void	if_stack_is_sorted(t_stack *stack_input)
{


}
