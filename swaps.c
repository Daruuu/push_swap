/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:01:03 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/21 18:42:05 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* SWAP DATA AND INDEX OF NODES*/

void	swap_node(t_stack *stack)
{
	int				temp_data;
	int				temp_index;
	struct t_node	*first;
	struct t_node	*second;
	
	temp_data = first->data;
	/*
	if (stack == NULL || stack->next == NULL)
		return ;
	 update value*/
	/*
	first = ;
	temp_data = stack->data;
	stack->data = stack->next->data;
	stack->next->data= temp_data;
	temp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp_index;
	*/
}

void	swap_a(t_node *stack_a)
{
	swap_nodes(stack_a);
}

void	swap_b(t_node *stack_b)
{
	swap_nodes(stack_b);
}

void	swap_a_b(t_node *stack)
{
	swap_a(stack);
	swap_b(stack);
}
