/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:57:52 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/16 21:00:56 by dasalaza         ###   ########.fr       */
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

/* Set indexes in STACK*/
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
			if (others->data < current->value)
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

int	stack_is_sorted(struct s_stack *stack_a)
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
