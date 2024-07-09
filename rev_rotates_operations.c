/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotates_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:15:08 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/10 00:24:45 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ROTATE LAST ELEMENT OF STACK TO FIRST POSITION OF STACK
 * |HEAD|-> |1|next| --> |prev|2|next|--> |prev|3|next|--> |prev|4|next|-->NULL
 *
 * |prev|2|next|--> |prev|3|next| --> |prev|4|next| --> |prev|1|next| --> NULL 
 * [10]	[4] [5] [1]
 *  _____________|
 *  |
 *  V
 * [1]	[10] [4] [5]
*/
void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*new_first;
	t_node	*new_last;

	if (stack == NULL || stack->len < 2)
		return ;
	new_first = get_tail_of_stack(stack);
	new_first->next = stack->head;
	new_last = get_before_last_node_stack(stack);
	new_last->next = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate_stack(*stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate_stack(*stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
