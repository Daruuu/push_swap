/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_no_using.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 22:37:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/29 23:16:10 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_node_position_id(t_stack *stack, int target_index)
{
	int		position;
	t_node	*current;

	current = stack->head;
	position = 0;
	while (current)
	{
		if (current->index == target_index)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

int	find_better_move(t_stack *stack, int max_index)
{
	t_node	*last_node;
	t_node	*current;

	last_node = get_tail_of_stack(stack);
	current = stack->head;
	while (current && last_node)
	{
		if (current->index < max_index)
			return (1);
		else if (last_node->index < max_index - 1)
			return (0);
		current = current->next;
		last_node = last_node->previous;
	}
	return (0);
}

int	stack_is_sorted_by_index(t_stack *stack_a)
{
	t_node	*current;

	if (stack_a == NULL || stack_a->head == NULL)
		return (EXIT_FAILURE);
	current = stack_a->head;
	while (current != NULL)
	{
		if (current->next != NULL && current->index > current->next->index)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
