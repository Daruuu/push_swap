/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:01:03 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/01 18:00:23 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* SWAP DATA AND INDEX OF NODES*/

void	swap_nodes(t_stack *stack)
{
	int		temp_data;
	int		temp_index;
	t_node	*first;
	t_node	*second;
	
	if (stack == NULL || stack->len < 2)
		return ;
	first = stack->head;
	second = stack->head->next;

	temp_data = first->data;
	first->data = second->data;
	second->data = temp_data;

	temp_index = first->index;
	first->index = second->index;
	second->index = temp_index;
}

void	swap_a(t_stack *stack_a)
{
	swap_nodes(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack_b)
{
	swap_nodes(stack_b);
	ft_printf("sb\n");
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
