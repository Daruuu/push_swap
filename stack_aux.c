/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/19 13:04:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Set indexes in STACK
 *	TODO: redo this functions with others variables names
*/

void	set_index_stack(t_stack *stack)
{
	t_node	*min_node;
	int		index;
	int		i;
	int 	current_threshold;

	min_node = find_min_node(stack, INT_MIN);
	min_node->index = 0;
	current_threshold = min_node->data;
	i = 1;
	index = 1;
	while (i < stack->len)
	{
		min_node = find_min_node(stack, current_threshold);
		min_node->index = index;
		current_threshold = min_node->data;
		index++;
		i++;
	}
}

t_node	*find_min_node(t_stack *stack,  int threshold)
{
	t_node	*current;
	t_node	*min_node;
	int 	min;

	if (stack == NULL || stack->head == NULL)
		return (0);
	current = stack->head;
	min = INT_MAX;
	min_node = current;
	while (current != NULL)
	{
		if (current->data < min && current->data > threshold)
		{
			min = current->data;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

/*
t_node	*find_min_node(t_stack *stack, int threshold)
{
	t_node	*current;
	t_node	*min_node;
	int 	min;

	current = stack->head;
	min_node = NULL;
	min = INT_MAX;

	while (current != NULL)
	{
		if (current->data < min && current->data > threshold )
		{
			min = current->data;
			min_node = current;
		}
		current = current->next;
	}
	return min_node;
}
*/

/*	flota el max number de un stack de 4 numbers	*/

void	float_min_number_four_stack(t_stack *stack_a)
{
	int		min_pos;

	min_pos = min_index_stack(stack_a);
	if (min_pos == 1)
		sa(stack_a);
	else if (min_pos == 2)
	{
		rra(&stack_a);
		rra(&stack_a);
	}
	else if (min_pos == 3)
		rra(&stack_a);
}

void	float_min_number_five_stack(t_stack *stack_a)
{
	int		min_pos;

	min_pos = min_index_stack(stack_a);
	if (min_pos == 1)
		sa(stack_a);
	else if (min_pos == 2)
	{
		ra(&stack_a);
		ra(&stack_a);
	}
	else if (min_pos == 3)
	{
		rra(&stack_a);
		rra(&stack_a);
	}
	else if (min_pos == 4)
		rra(&stack_a);
}
