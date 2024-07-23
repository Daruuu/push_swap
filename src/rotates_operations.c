/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/21 19:38:10 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL || stack->len < 2)
		return ;
	first = stack->head;
	last = stack->tail;
	stack->head = first->next;
	stack->head->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	stack->tail = first;
}

void	ra(t_stack **stack_a)
{
	rotate_stack(*stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate_stack(*stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
}
