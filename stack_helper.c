/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_list_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:13:56 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/03 12:00:02 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * get the last before node in stack
 */

t_node	*get_before_last_node_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->len < 2)
		return (NULL);
	current = stack->head;
	while (current->next->next != NULL)
		current = current->next;
	return (current);
}

/*
 * get last NODE of stack
 * iterate throught the stack and return the last NODE
*/

t_node	*get_tail_of_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current= current->next;
	return (current);
}
