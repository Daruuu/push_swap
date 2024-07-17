/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/17 18:38:23 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Set indexes in STACK
 *	TODO: redo this functions with others variables names
*/

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
	else if (min_pos ==  2)
	{
		ra(&stack_a);
		ra(&stack_a);
	}
	else if (min_pos ==  3)
	{
		rra(&stack_a);
		rra(&stack_a);
	}
	else if (min_pos == 4)
		rra(&stack_a);
}