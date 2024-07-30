/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/30 12:17:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_chunks_from_a_to_b(t_stack *stk_a, t_stack *stk_b, int chunk_size)
{
	int	chunk_multiplier;

	chunk_multiplier = 1;
	while (ft_size_stack(stk_a) != 1)
	{
		if (stk_a->head->index < chunk_size * chunk_multiplier)
		{
			push_b(&stk_a, &stk_b);
			if (stk_b && stk_b->head->next && stk_b->head->index
				< (chunk_size * chunk_multiplier - chunk_size / 2))
				rb(&stk_b);
		}
		else if (best_direction_to_rotate(stk_a, stk_b->len + 1) == 1)
			ra(&stk_a);
		else
			rra(&stk_a);
		if (stk_b->len == chunk_size * chunk_multiplier)
			chunk_multiplier++;
	}
	while (ft_size_stack(stk_a) != 0)
		push_b(&stk_a, &stk_b);
}

void	move_chunks_from_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	index_to_move;
	int	node_to_move_to_a;

	while (ft_size_stack(stack_b) != 0)
	{
		index_to_move = ft_size_stack(stack_b) - 1;
		node_to_move_to_a = find_index_position(stack_b, index_to_move);
		rotate_to_top_b(stack_b, node_to_move_to_a);
		push_a(&stack_b, &stack_a);
	}
}
