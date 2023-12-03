/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:01:03 by dasalaza          #+#    #+#             */
/*   Updated: 2023/12/03 08:32:48 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * function to order stack in order of value
 * TODO: function to remake with other way
*/

void	sort_stack_ascendent(t_node **head_ref)
{
	t_node	*sort_stack;
	t_node	*current_node;
	t_node	*next_node;
	t_node	*tmp;

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
			tmp = sort_stack;
			while (tmp->next != NULL && tmp->next->index < current_node->index)
				tmp = tmp->next;
			current_node->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->previous = current_node;
			tmp->next = current_node;
			current_node->previous = tmp;
		}
		current_node = next_node;
	}
	*head_ref = sort_stack;
}

void	ft_swap(int *a, int *b)
{
	int	*tmp;

	tmp = NULL;
	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

void	swap_nodes(t_node *node_a, t_node *node_b)
{
	int	temp_value;
	int	temp_index;

	temp_value = node_a->value;
	temp_index = node_a->index;
	node_a->index = node_b->index;
	node_a->value = node_b->value;
	node_b->index = temp_index;
	node_b->value = temp_value;
}

/*
 * function if input ist are sorted, finish the program 
*/
/*
void	if_stack_is_sorted(t_stack *stack_input)
{

}
*/
