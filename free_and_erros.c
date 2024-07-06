/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_erros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:30:52 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/06 14:17:59 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * FREE EACH NODE IN LINKED LIST
*/

void	free_each_node(t_stack **stack)
{
	t_node	*current;
	t_node	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	current = (*stack)->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stack);
	*stack = NULL;
}

/*
 * FREE A NODE
*/
void	free_node(t_node *node)
{
	t_node	*current;
	t_node	*next;

	if (node)
		free(node);
	node = NULL;
}
