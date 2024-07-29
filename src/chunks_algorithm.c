/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/29 22:33:01 by dasalaza         ###   ########.fr       */
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
		else if (last_node->index < max_index - 1)	// original
		//else if (last_node->index)
			return (0);
		current = current->next;
		last_node = last_node->previous;
	}
	return (0);
}

int	best_direction_to_rotate(t_stack *stack_a, int current_index)
{
	t_node	*current;
	int		len_stack;
	int		n_ra_moves;
	int		n_rra_moves;

	len_stack = ft_size_stack(stack_a);
	n_ra_moves = 0;
	current = stack_a->head;
	int	i = 0;
/*
	ft_printf("---------------------\n");
	ft_printf("BEST DIRECTION_TO_ROTATE(): %d\n", i);
	ft_printf("---------------------|\n");
*/
	i++;
	while (current != NULL && n_ra_moves < len_stack/2)
	{
		if (current->index >= current_index)
			n_ra_moves++;
		else
			break;
		current = current->next;
	}
	current = get_tail_of_stack(stack_a);
	n_rra_moves = 0;
	//while (current != NULL && n_rra_moves < len_stack/2)
	while (current != NULL && n_rra_moves < len_stack / 2)// ??????
	{
		if (current->index > current_index)
			n_rra_moves++;
		else
		{
			n_rra_moves++;
			break;
		// exit of loop bucle porque hemos encontrado un INDEX menor al del current_index
		}
		current = current->previous;
	}
/*
	ft_printf("ra MOVES: %d\n", n_ra_moves);
	ft_printf("rra MOVES: %d\n", n_rra_moves);
	ft_printf("RA - RRA: %d - %d = %d\n",n_ra_moves, n_rra_moves, n_ra_moves <= n_rra_moves);
	ft_printf("ra : 1\n");
	ft_printf("rra: 0\n");
	ft_printf("---------------------|\n");
*/
	if (n_ra_moves <= n_rra_moves)
		return (1);	//	ra
	else
		return (0);	//	rra
}

void	move_nodes_from_a_to_b(t_stack *stk_a, t_stack *stk_b, int chunk_size)
{
	int	chunk_multiplier;

	chunk_multiplier = 1;
	int i = 0;
/*
	ft_printf("---------------------\n");
	ft_printf("MOVE_NODES_A_TO_B(): %d\n", i);
	ft_printf("---------------------\n");
	ft_printf("CHUNK MULTIPLIER: %d\n", chunk_multiplier);
	ft_printf("ITERACION: %d\n", i);
*/
//	print_stacks(stk_a, stk_b);
//	ft_printf("\n");
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
		if (stk_b->len == chunk_size * chunk_multiplier)// cambiar de chunk
			chunk_multiplier++;
		i++;
//		print_stacks(stk_a, stk_b);
	}
	while (ft_size_stack(stk_a) != 0)
		push_b(&stk_a, &stk_b);
	//	printf("stack a is now empty i moved in chunks well\n");
}

int		find_index_position(t_stack *stack_b, int index_to_move_to_a);
void	rotate_to_top_b(t_stack *stack_b, int position);

void	move_nodes_from_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	index_to_move;
	int	node_to_move_to_a;
	int i = 0;
//	ft_printf("MOVE_NODES_B_TO_A() :\n");
//	while (stack_b != NULL && ft_size_stack(stack_b) != 0)
//	ft_printf("SIZE STACK B: %d \n", ft_size_stack(stack_b));
	while (ft_size_stack(stack_b) != 0)
	{
//		ft_printf("ITERACION : %d\n", i);
		index_to_move = ft_size_stack(stack_b) - 1;
//		ft_printf("ITERATION: %d\n", i);
//		ft_printf("INDEX_TO_MOVE STACK_B: %d\n", index_to_move);
		node_to_move_to_a = find_index_position(stack_b, index_to_move);

		rotate_to_top_b(stack_b, node_to_move_to_a);

		push_a(&stack_b, &stack_a);
//		if (index_to_move == node_to_move_to_a)
//			push_a(&stack_b, &stack_a);
//		last_node_index = get_tail_of_stack(stack_b)->index;
//		current_b = current_b->next;
		i++;
	}
}

// Rota el stack_b para que el nodo en la posición dada esté en la cima
void	rotate_to_top_b(t_stack *stack_b, int position)
{
//	int	size;
	int	half_size;
	int	n_rb_moves;
	int	n_rrb_moves;

	half_size = ft_size_stack(stack_b) / 2;
//	size = ft_size_stack(stack_b);
	n_rb_moves = 0;
	if (position <= half_size)	//  posible error !!! <=
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

// Encuentra la posición del nodo con el índice dado en el stack_b
int	find_index_position(t_stack *stack_b, int index_to_move_to_a)
{
	t_node *current;
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

/*
int	best_direction_to_rotate_b(t_stack *stack_b, int index_to_find)
{
	t_node	*current;
	int		len_stack_b;
	int		n_rb_moves;
	int		n_rrb_moves;

	len_stack_b = ft_size_stack(stack_b);
	n_rb_moves = 0;
	current = stack_b->head;
	int	i = 0;
	i++;
*/
/*
	ft_printf("---------------------\n");
	ft_printf("BEST DIRECTION_TO_ROTATE(): %d\n", i);
	ft_printf("---------------------|\n");
*/
/*

	while (current != NULL && n_rb_moves < len_stack_b / 2)
	{
		if (current->index >= index_to_find)
			n_rb_moves++;
		else
			break;
		current = current->next;
	}
	current = get_tail_of_stack(stack_b);
	n_rrb_moves = 0;
	//while (current != NULL && n_rrb_moves < len_stack_b/2)
	while (current != NULL || n_rrb_moves < len_stack_b / 2)// ??????
	{
		if (current->index > index_to_find)
			n_rrb_moves++;
		else
		{
			n_rrb_moves++;
// exit of loop bucle porque hemos encontrado un INDEX menor al del index_to_find
			break;
		}
		current = current->previous;
	}
*/
/*
	ft_printf("ra MOVES: %d\n", n_rb_moves);
	ft_printf("rra MOVES: %d\n", n_rrb_moves);
	ft_printf("RA - RRA: %d - %d = %d\n",n_rb_moves, n_rrb_moves, n_rb_moves <= n_rrb_moves);
	ft_printf("ra : 1\n");
	ft_printf("rra: 0\n");
	ft_printf("---------------------|\n");

*/
//printf("Ahora en top hay index %d\n", stk_b->head->index);
//printf("while 1\n");
/*
if (stk_b->head != NULL && stk_b->head->index >= max_index_stk_b - 2)
{
	printf("enter first if\n");
	push_a(&stk_b, &stk_a);
	if (stk_a && stk_a->head && (stk_a->head->index == max_index_stk_b - 2)){
		printf("case 1\n");
		ra(&stk_a);
	}
	else if (stk_a && stk_a->head && stk_a->head->next && (stk_a->head->index - stk_a->head->next->index == 1))
	{
		printf("case 2\n");
		sa(stk_a);
	}
	if (stk_a && stk_a->head && stk_a->head->index && (stk_a->head->next->index - get_tail_of_stack(stk_a)->index == 2
		|| stk_a->head->index - get_tail_of_stack(stk_a)->index == 2)){
		printf("case 2\n");
		rra(&stk_a);
	}
	printf("getting out of first if\n");
}
else if (find_node_position_id(stk_b, max_index_stk_b)
	> ft_size_stack(stk_b) / 2)
	rrb(&stk_b);
else if (stk_b->head != NULL)
	rb(&stk_b);
*/


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
