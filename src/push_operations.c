/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:43:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/16 01:20:32 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * send FIRST NODE
 * of STACK_SRC to
 * STACK_DEST in the
 * 1rst POS of STACK
*/

void	push_move(t_stack **stack_src, t_stack **stack_dest)
{
	t_node	*tmp_first_node_src;

	if (*stack_src == NULL || (*stack_src)->head == NULL)
		return ;
	tmp_first_node_src = (*stack_src)->head;
	(*stack_src)->head = (*stack_src)->head->next;
	if ((*stack_src)->head != NULL)
		(*stack_src)->head->previous = NULL;
	else
		(*stack_src)->tail = NULL;
	tmp_first_node_src->next = (*stack_dest)->head;
	tmp_first_node_src->previous = NULL;
	if ((*stack_dest)->head != NULL)
		(*stack_dest)->head->previous = tmp_first_node_src;
	else
		(*stack_dest)->tail = tmp_first_node_src;
	(*stack_dest)->head = tmp_first_node_src;
	(*stack_src)->len--;
	(*stack_dest)->len++;
}

void	push_a(t_stack **stack_src, t_stack **stack_dest)
{
	push_move(&(*stack_src), &(*stack_dest));
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_src, t_stack **stack_dest)
{
	push_move(&(*stack_src), &(*stack_dest));
	ft_printf("pb\n");
}
