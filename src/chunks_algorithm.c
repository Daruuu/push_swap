/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/27 19:32:06 by dasalaza         ###   ########.fr       */
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

void	move_nodes_from_a_to_b(t_stack *stk_a, t_stack *stk_b, int chunk_size)
{
	int	chunk_multiplier;

	chunk_multiplier = 1;
	int i = 0;
//	 while (stack_is_sorted_by_index(stk_a) == 0 && i <= 256)
	while (stack_is_sorted_by_index(stk_a) == 0)
	{
		if (stk_a->head->index < chunk_size * chunk_multiplier
			&& stk_a->head->index < max_index_stack(stk_a) - 1)
		{
			push_b(&stk_a, &stk_b);
			if (stk_b && stk_b->head->next && stk_b->head->index
				< (chunk_size * chunk_multiplier - chunk_size / 2))
				rb(&stk_b);
		}
/* PROBLEM HEREE !!!!!!!!!!!!!*/
		else if (find_better_move(stk_a, chunk_size * chunk_multiplier))
			ra(&stk_a);
		else
			rra(&stk_a);
		if (stk_b->len == chunk_size * chunk_multiplier)
			chunk_multiplier++;
		i++;
		ft_printf("ITERACION: %d\n", i);
		ft_printf("CHUNK MULTIPLIER %d\n", chunk_multiplier);
		print_stacks(stk_a, stk_b);
	}
}

/*
 * funcion la cual encuentre:
 * cual es el mejor moviemiento para el indice actual:
 * basarnos en:
 *		stack_a->index esta dentro del rango del CHUNK ACTUAL
 *		si el siguiente nodo esta dentro del stack actual
 *		si la 1ra MITAD del chunk hay INDICES que pertenecen al CHUNK ACTUAL
 *		
 *		si la 2da MITAD del chunk hay INDICES que pertenecen al CHUNK ACTUAL
 *
 *		que movimientos ES MAS EFICIENTE realizar si RRA o RA
*/
//int	best_move_in_node_actual(t_stack *stack_a, int chunk_size)
int	best_move_in_node_actual(t_stack *stack_a)
{
	t_node	*current;
	int		len_stack;
	int		first_half_count;
	int		second_half_count;
	int		i;

	current = stack_a->head;
	len_stack = ft_size_stack(stack_a);
	first_half_count = 0;
	second_half_count = 0;
	i = 0;
	while (current != NULL)
	{
		if (current->index < len_stack / 2)
		{
			if (i < len_stack / 2)
				first_half_count++;
			else
				second_half_count;
		}
		i++;
		current = current->next;
	}
	if (first_half_count >= second_half_count)
		return (1);	//	ra
	else
		return (0);	//	rra
}

/*
int	best_move_in_node_actual(t_stack *stack_a, int chunk_size)
{
	t_node	*current;
	int		len_stack;
	int		first_half_count;
	int		second_half_count;
	int		i;

	current = stack_a->head;
	len_stack = ft_size_stack(stack_a);
	first_half_count = 0;
	second_half_count = 0;
	i = 0;
	while (current != NULL && i < len_stack)
	{
		if (current->index < chunk_size)
			first_half_count++;
		else
			current->next;
		i++;
	}
	current = current->next;
	if (first_half_count >= second_half_count)
		return (1);	//	ra
	else
		return (0);	//	rra
}
*/
void	move_nodes_from_b_to_a(t_stack *stk_a, t_stack *stk_b)
{
	int	max_index_stk_b;

	while (stk_b->head)
	{
		max_index_stk_b = max_index_stack(stk_b);
		if (stk_b->head != NULL && stk_b->head->index >= max_index_stk_b - 2)
		{
			push_a(&stk_b, &stk_a);
			if (stk_a->head->index == max_index_stk_b - 2)
				ra(&stk_a);
			else if (stk_a->head->index - stk_a->head->next->index == 1)
				sa(stk_a);
			if (stk_a->head->next->index - get_tail_of_stack(stk_a)->index == 2
				|| stk_a->head->index - get_tail_of_stack(stk_a)->index == 2)
				rra(&stk_a);
		}
		else if (find_node_position_id(stk_b, max_index_stk_b)
			> ft_size_stack(stk_b) / 2)
			rrb(&stk_b);
		else if (stk_b->head != NULL)
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
		if (current->next != NULL && current->index > current->next->index)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

/*
 * BACKUP FILE
void	move_nodes_from_b_to_a(t_stack *stk_a, t_stack *stk_b)
{
	int	max_index_stk_b;

	while (stk_b->head)
	{
		max_index_stk_b = max_index_stack(stk_b);
		if (stk_b->head != NULL && stk_b->head->index >= max_index_stk_b - 2)
		{
			push_a(&stk_b, &stk_a);
			if (stk_a->head->index == max_index_stk_b - 2)
				ra(&stk_a);
			else if (stk_a->head->index - stk_a->head->next->index == 1)
				sa(stk_a);
			if (stk_a->head->next->index - get_tail_of_stack(stk_a)->index == 2
				|| stk_a->head->index - get_tail_of_stack(stk_a)->index == 2)
				rra(&stk_a);
		}
		else if (find_node_position_id(stk_b, max_index_stk_b)
			> ft_size_stack(stk_b) / 2)
			rrb(&stk_b);
		else if (stk_b->head != NULL)
			rb(&stk_b);
	}
}
*/

/*
void	move_nodes_from_b_to_a(t_stack *stk_a, t_stack *stk_b)
{
	int	max_index_stk_b;
	int	stack_size_b;

	while (stk_b->head)
	{
		max_index_stk_b = max_index_stack(stk_b);
		stack_size_b = ft_size_stack(stk_b); // Calculate size once per loop

		while (stk_b->head && stk_b->head->index >= max_index_stk_b - 2)
		{
			push_a(&stk_b, &stk_a);
			if (stk_a->head->index == max_index_stk_b - 2)
				ra(&stk_a);
			else if (stk_a->head->index - stk_a->head->next->index == 1)
				sa(stk_a);
			int tail_index = get_tail_of_stack(stk_a)->index;
			if (stk_a->head->next->index - tail_index == 2 || stk_a->head->index - tail_index == 2)
				rra(&stk_a);
		}

		if (find_node_position_id(stk_b, max_index_stk_b) > stack_size_b / 2)
			rrb(&stk_b);
		else if (stk_b->head)
			rb(&stk_b);
	}
}
*/
