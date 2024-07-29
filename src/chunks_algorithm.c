/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/29 14:04:29 by dasalaza         ###   ########.fr       */
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

void	move_nodes_from_a_to_b(t_stack *stk_a, t_stack *stk_b, int chunk_size)
{
	int	chunk_multiplier;

	chunk_multiplier = 1;
	int i = 0;
	//ft_printf("ITERACION: %d\n", i);
	ft_printf("---------------------\n");
	ft_printf("MOVE_NODES_A_TO_B(): %d\n", i);
	ft_printf("---------------------\n");
	ft_printf("CHUNK MULTIPLIER: %d\n", chunk_multiplier);
	ft_printf("ITERACION: %d\n", i);

	print_stacks(stk_a, stk_b);

	ft_printf("\n");

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
		print_stacks(stk_a, stk_b);
	}
	while(ft_size_stack(stk_a) != 0)
		push_b(&stk_a, &stk_b);
//	printf("stack a is now empty i moved in chunks well\n");
}

/*
 * funcion la cual encuentre:
 * cual es el mejor moviemiento para el indice actual:
 * basarnos en:
 *		stack_a->index esta dentro del rango del CHUNK ACTUAL
 *		si el siguiente nodo esta dentro del stack actual
 *		si la 1ra MITAD del chunk hay INDICES que pertenecen al CHUNK ACTUAL
 *		si la 2da MITAD del chunk hay INDICES que pertenecen al CHUNK ACTUAL
 *		que movimientos ES MAS EFICIENTE realizar si RRA o RA
 *
 *		@current_index: chunk_size * chunk_interation
*/

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
	i++;
	ft_printf("---------------------\n");
	ft_printf("BEST DIRECTION_TO_ROTATE(): %d\n", i);
	ft_printf("---------------------|\n");
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
	while (current != NULL && n_rra_moves < len_stack/2)// ??????
	{
		if (current->index > current_index)
			n_rra_moves++;
		else
		{
			n_rra_moves++;
// exit of loop bucle porque hemos encontrado un INDEX menor al del current_index
			break;
		}
		current = current->previous;
	}
	ft_printf("ra MOVES: %d\n", n_ra_moves);
	ft_printf("rra MOVES: %d\n", n_rra_moves);
	ft_printf("RA - RRA: %d - %d = %d\n",n_ra_moves, n_rra_moves, n_ra_moves <= n_rra_moves);
	ft_printf("ra : 1\n");
	ft_printf("rra: 0\n");
	ft_printf("---------------------|\n");
	if (n_ra_moves <= n_rra_moves)
		return (1);	//	ra
	else
		return (0);	//	rra
}

/*
 * function to put index of stack B in top
 * ra o rrb
*/
/*
int	put_index_in_top_of_b(t_stack *stack_a, t_stack *stack_b, int index_find)
{
	int		last_node_index;
	int		len_stack_b;

	//last_node_stack_b = get_tail_of_stack(stack_b)->index;
	last_node_index = get_tail_of_stack(stack_b)->index;
	//index_last_node = last_node_stack_b->index;
	len_stack_b = ft_size_stack(stack_b);
	while (stack_b != NULL)
	{
		last_node_index = get_tail_of_stack(stack_b)->index;
		//	10 - 1 == 9	 || 10 -2  == 9
		if (len_stack_b - 1 == index_find || len_stack_b - 2 == index_find)
			push_a(&stack_b, &stack_a);
		else if (last_node_index == index_find)
			rra(&stack_b);
			return (1);	//	
		else
			return (0);
		stack_b->index
	}
	return ();
}
*/
void	move_nodes_from_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	index_to_move;
	int	last_node_index;

	int	i = 0;
	last_node_index = get_tail_of_stack(stack_b)->index;
	printf("MOVE_NODES_B_TO_A() :\n");
	while (stack_b->head)
	{
		ft_printf("ITERACION : %d\n", i);
		index_to_move = ft_size_stack(stack_b) - 1;
		printf("INDEX_TO_MOVE : %d\n", index_to_move);
		if(stack_b->head->index == index_to_move)
		{
			ft_printf("STACK_B->index == INDEX_TO_MOVE\n",stack_b->head->index, index_to_move);
			ft_printf(" %d\t\t == \t\t%d\n", stack_b->head->index, index_to_move);
			push_a(&stack_b, &stack_a);
		}
		else if (last_node_index == index_to_move)
			rrb(&stack_b);
		else
			rb(&stack_b);
		i++;
	}
}

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
