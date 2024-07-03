/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/02 11:34:14 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ROTATE FIRST ELEMENT OF STACK TO LAST POSITION 
 * |HEAD|-> |1|next| --> |prev|2|next|--> |prev|3|next| --> |prev|4|next| --> NULL
 *
 * |prev|2|next|--> |prev|3|next| --> |prev|4|next| --> |prev|1|next| --> NULL 
 * [10]	[4] [5] [1]
 * [4]	[5] [5] [1]
 * [5]	[1] [5] [1]
 * [1]	[10] [5] [1]
 * ra
*/
void	rotate_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL || stack->len < 2)
		return ;
	/*	inicializar los punteros al primer y ultimo nodo*/
	first = stack->head;
	last = stack->tail;
	/* desvincular el primer NODO al FINAL de la pila*/
	stack->head = first->next; 
	stack->head->previous = NULL;
	/*	recolorcar el primer nodo al funal de stack*/
	last->next = first;
	first->previous = last;
	first->next = NULL;
	stack->tail = first;
}

void	rotate_a(t_stack **stack_a)
{
	rotate_stack(*stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	rotate_stack(*stack_b);
	ft_printf("rb\n");
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_printf("rr\n");
}
