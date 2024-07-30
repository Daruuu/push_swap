/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 12:09:39 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/30 12:30:10 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	number_ra_moves(t_stack *stack, int target_index)
{
	t_node	*current;
	int		n_ra_moves;

	n_ra_moves = 0;
	current = stack->head;
	while (current != NULL && n_ra_moves < stack->len / 2)
	{
		if (current->index >= target_index)
			n_ra_moves ++;
		else
			break ;
		current = current->next;
	}
	return (n_ra_moves);
}

static int	number_rra_moves(t_stack *stack, int target_index)
{
	t_node	*current;
	int		n_rra_moves;

	current = get_tail_of_stack(stack);
	n_rra_moves = 0;
	while (current != NULL && n_rra_moves < stack->len / 2)
	{
		if (current->index >= target_index)
			n_rra_moves ++;
		else
		{
			n_rra_moves ++;
			break ;
		}
		current = current->previous;
	}
	return (n_rra_moves);
}

int	best_direction_to_rotate(t_stack *stack_a, int target_index)
{
	int		n_ra_moves;
	int		n_rra_moves;

	n_ra_moves = number_ra_moves(stack_a, target_index);
	n_rra_moves = number_rra_moves(stack_a, target_index);
	if (n_ra_moves <= n_rra_moves)
		return (1);
	else
		return (0);
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
