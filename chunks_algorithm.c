/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/20 03:34:05 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	return the position NUMBER in STACK usign INDEX
 */
int	max_index_stack(t_stack *stack) {
	int		index;
	t_node	*current;

	current = stack->head;
	index = -1;
	while (current)
	{
		if (current->index > index)
			index = current->index;
		current = current->next;
	}
	return (index);
}

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

/*
 * determinar si es mas eficiente mover un NUMERO desde el principio
 * o desde el final del stack
 */

int	find_better_move(t_stack *stack, int max_index)
{
	t_node	*last_node;
	t_node	*current;

//	last_node = stack->tail;
	last_node = get_tail_of_stack(stack);
	current = stack->head;
	while (current && last_node)
	{
		if (current->index < max_index)
			return (1);
		else if (last_node->index < max_index)
			return (0);
		current = current->next;
		last_node = last_node->previous;
	}
	return (0);
}

void	move_nodes_from_a_to_b(t_stack *stk_a, t_stack *stk_b, int chunk_size)
{
	int	chunk_multiplier;

	chunk_multiplier = 1;
	//	sorted by index	??
	while (stack_is_sorted_by_index(stk_a) != 0)
	{
//		if (stk_a->head->index < chunk_size * chunk_multiplier && stk_a->head->index < max_index(*stk_a) - 1) {
		if ((stk_a->head->index < chunk_size * chunk_multiplier) && (stk_a->head->index < stk_a->len - 1))
		{
			push_b(&stk_a, &stk_b);
			// 20 * 1 - 20 / 2 ->  20 - 10
			if (stk_b && stk_b->head->next && stk_b->head->index < (chunk_size * chunk_multiplier - chunk_size / 2))
				rb(&stk_b);
		} else if (find_better_move(stk_a, chunk_size * chunk_multiplier)) {
			rra(&stk_a);
		} else {
			ra(&stk_a);
		}
		//	comparo que el 1er chunk haya terminado ; para avanzar al siguiente chunk
		if (stk_b->len == chunk_size * chunk_multiplier)
			chunk_multiplier++;
	}
}

/*
 * return the STACK in correct ORDER
 */
void	move_nodes_from_b_to_a(t_stack *stk_a, t_stack *stk_b)
{
	int max_index_stk_b;

	while (stk_b)
	{
		max_index_stk_b = max_index_stack(stk_b);
//		max_index_stk_b = stk_b->len - 1;	// max_index = find_max_index_stack_b();
		// si el indice del head B es MAYOR IGUAL que lenght STACK B - 2
		if (stk_b->head->index >= max_index_stk_b - 2)
		{
			push_a(&stk_b, &stk_a);
			// si el indice del head es igual que lenght- 2 de STACK B
			if (stk_a->head->index == max_index_stk_b - 2)
				ra(&stk_a);
			else if (stk_a->head->index - stk_a->head->index == 1)
				sa(stk_a);
			if (stk_a->head->next->index - get_tail_of_stack(stk_a)->index == 2 ||
				stk_a->head->index - get_tail_of_stack(stk_a)->index == 2)
				rra(&stk_a);
		}
		else if (find_node_position_id(stk_b, max_index_stk_b)
				> ft_size_stack(stk_b) / 2)
			rrb(&stk_b);
		else
			rb(&stk_b);
	}
}

int	stack_is_sorted_by_index(t_stack *stack_a)
{
	t_node	*current;

	if (stack_a == NULL || stack_a->head == NULL)
		return (EXIT_FAILURE);
	current = stack_a->head;
	while (current != NULL)
	{
		if (current->index > current->next->index)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
/*
 * function to order each chunk
 * redondear cada chunk hacia arriba
 * 2 4 20 19 15 1 9 13 10 11 16 3 8 14 12 18 7 17 6 5
 * chunk 1:	2 4 20 19 15 
 * chunk 2:	1 9 13 10 11 
 * chunk 3:	16 3 8 14 12
 * chunk 4:	18 7 17 6 5
*/
/*
void	sort_stack_with_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	i;
	int	j;
	int	min_value_chunk;
	int	max_value_chunk;

	i = 0;
	while (i < stack_a->len)
	{
		j = 0;
		while (j < chunk_size)
		{
			//	chunk 1:	2 4 20 19 15 
			min_value_chunk = min_index_chunk(stack_a, chunk_size);	//	2
			max_value_chunk = max_index_stack(stack_a);	//	20
			ft_printf("%d\n", min_value_chunk);
			ft_printf("%d\n", max_index_stack);
			if (stack_a->head->data >= min_value_chunk
					&& stack_a->head->data <= max_value_chunk)
				push_b(&stack_a, &stack_b);
			else
				ra(&stack_a);
			j++;
		}
		i++;
	}
}
*/

/*
int	min_index_chunk(t_stack *stack, int len_chunk)
{
	int		min;
	int		index;
	int		min_index;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (0);
	current = stack->head;
	min = current->data;
	index = 0;
	min_index = index;
	while (current != NULL && stack->len != len_chunk - 1)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = index;
		}
		index++;
		current = current->next;
		len_chunk++;
	}
	return (min_index);
}
int	max_index_chunk(t_stack *stack, int chunk_size)
{
	int		max;
	int		index;
	int		max_index;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (0);
	current = stack->head;
	max = current->data;
	index = 0;
	max_index = index;
	while (current != NULL && stack->len != chunk_size)
	{
		if (current->data > max)
		{
			max = current->data;
			max_index = index;
		}
		index++;
		current = current->next;
	}
	return (max_index);
}
*/