/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/30 00:35:31 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	best_direction_to_rotate(t_stack *stack_a, int current_index)
{
	t_node	*current;
	int		len_stack;
	int		n_ra_moves;
	int		n_rra_moves;

	len_stack = ft_size_stack(stack_a);
	n_ra_moves = 0;
	current = stack_a->head;
	while (current != NULL && n_ra_moves < len_stack / 2)
	{
		if (current->index >= current_index)
			n_ra_moves ++;
		else
			break ;
		current = current->next;
	}
	current = get_tail_of_stack(stack_a);
	n_rra_moves = 0;
	while (current != NULL && n_rra_moves < len_stack / 2)
	{
		if (current->index >= current_index)
			n_rra_moves ++;
		else
		{
			n_rra_moves ++;
			break ;
		}
		current = current->previous;
	}
	if (n_ra_moves <= n_rra_moves)
		return (1);
	else
		return (0);
}

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

void	rotate_to_top_b(t_stack *stack_b, int position)
{
	int	half_size;
	int	n_rb_moves;
	int	n_rrb_moves;

	half_size = ft_size_stack(stack_b) / 2;
	n_rb_moves = 0;
	if (position <= half_size)
	{
		while (n_rb_moves < position)
		{
			rb(&stack_b);
			n_rb_moves++;
		}
	}
	else
	{
		half_size = ft_size_stack(stack_b) - position;
		n_rrb_moves = 0;
		while (n_rrb_moves < half_size)
		{
			rrb(&stack_b);
			n_rrb_moves++;
		}
	}
}

int	find_index_position(t_stack *stack_b, int index_to_move_to_a)
{
	t_node	*current;
	int		position;

	current = stack_b->head;
	position = 0;
	while (current != NULL)
	{
		if (current->index == index_to_move_to_a)
			return (position);
		current = current->next;
		position++;
	}
	return (position);
}
