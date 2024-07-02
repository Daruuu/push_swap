/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:43:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/02 21:03:27 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 *	enviar el primer node de STACK_SRC a 
 *	el STACK_DEST en la 1ra posicion del stack
 *
*/

void	push_move(t_stack *stack_src, t_stack *stack_dest)
{
	t_node	*node_to_mv_a_new_stack;
	t_node	*new_head_src;

	if (*stack_src == NULL || stack_src->head == NULL)
		return ;
	node_to_mv_a_new_stack = stack_src->head;
	stack_dest->head = node_to_mv_a_new_stack;
	node_to_mv_a_new_stack->next = stack_dest->head->next;
	new_head_src = stack_src->head->next;
	stack_src->head = new_head_src;
}

/*
void	push_move(t_stack *stack_src, t_stack *stack_dest)
{
	t_node	*tmp;

	if (*stack_src == NULL || stack_src->head == NULL)
		return ;
	tmp = stack_src->head;
	(*stack_src)->head = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = tmp;
}
*/
