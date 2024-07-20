/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/20 17:29:28 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	return the position NUMBER in STACK usign INDEX
 */
int	max_index_stack(t_stack *stack)
{
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

static void	print_stack_new(t_stack *stack_a, t_stack *stack_b);

void	move_nodes_from_a_to_b(t_stack *stk_a, t_stack *stk_b, int chunk_size)
{
	int	chunk_multiplier;

	chunk_multiplier = 1;
	while (stack_is_sorted_by_index(stk_a) == 0)
	{
		if (stk_a->head->index < chunk_size * chunk_multiplier && stk_a->head->index < max_index_stack(stk_a) - 1)
		{
			push_b(&stk_a, &stk_b);
			if (stk_b && stk_b->head->next && stk_b->head->index < (chunk_size * chunk_multiplier - chunk_size / 2))
				rb(&stk_b);
		} else if (find_better_move(stk_a, chunk_size * chunk_multiplier)) {
			ra(&stk_a);
		} else {
			rra(&stk_a);
		}
		//	comparo que el 1er chunk haya terminado ; para avanzar al siguiente chunk
		if (stk_b->len == chunk_size * chunk_multiplier)
			chunk_multiplier++;
		print_stack_new(stk_a, stk_b);
	}
}

static void print_stack_new(t_stack *stack_a, t_stack *stack_b)
{
	t_node *current_a;
	t_node *current_b;
	int stack_a_finished;
	int stack_b_finished;

	if (!stack_a && !stack_b)
		return;

	stack_a_finished = 0;
	stack_b_finished = 0;
	current_a = stack_a ? stack_a->head : NULL;
	current_b = stack_b ? stack_b->head : NULL;

	printf("PRINT STACKS :\n");
	while (!stack_a_finished || !stack_b_finished)
	{
		if (current_a)
		{
			printf("%d\t", current_a->data);
			current_a = current_a->next;
		}
		else
		{
			printf("\t"); // Imprimir un tabulador si stack_a ha terminado
			stack_a_finished = 1;
		}

		if (current_b)
		{
			printf("%d\n", current_b->data);
			current_b = current_b->next;
		}
		else
		{
			printf("\n"); // Imprimir una nueva línea si stack_b ha terminado
			stack_b_finished = 1;
		}
	}
	printf("------\n"); // Línea horizontal
	printf("a\tb\n"); // Indicadores de pila
	printf("\n");
}

/*
 * return the STACK in correct ORDER
 */

void	move_nodes_from_b_to_a(t_stack *stk_a, t_stack *stk_b)
{
	int max_index_stk_b;

	while (stk_b->head)
	{
		max_index_stk_b = max_index_stack(stk_b);
		// si el indice del head B es MAYOR IGUAL que lenght STACK B - 2
		if (stk_b->head != NULL && stk_b->head->index >= max_index_stk_b - 2)
		{
			push_a(&stk_b, &stk_a);
			print_stack_new(stk_a, stk_b);
			if (stk_a->head->index == max_index_stk_b - 2)
				ra(&stk_a);
			else if (stk_a->head->index - stk_a->head->next->index == 1)
				sa(stk_a);
			if (stk_a->head->next->index - get_tail_of_stack(stk_a)->index == 2 ||
				stk_a->head->index - get_tail_of_stack(stk_a)->index == 2)
				rra(&stk_a);
		}
		else if (find_node_position_id(stk_b, max_index_stk_b)
				> ft_size_stack(stk_b) / 2)
			rrb(&stk_b);
		else if (stk_b->head != NULL)
			rb(&stk_b);
		print_stack_new(stk_a, stk_b);
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