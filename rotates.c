/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/20 01:57:30 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ROTATE FIRST ELEMENT OF STACK TO LAST POSITION 
 * |HEAD|-> |1|next| --> |prev|2|next|--> |prev|3|next| --> |prev|4|next| --> NULL
 *
 * |prev|2|next|--> |prev|3|next| --> |prev|4|next| --> |prev|1|next| --> NULL 
*/
void	rotate_a(t_stack **stack)
{
	// encontrar el ultimo nodo del STACK
	// TODO: function to continue !!!
	int	len_stack;
	t_node	*current;
	t_node	*current_to_change;
	int		i;

	len_stack = ft_size_stack(*stack);
	// dereferenciar el ultimo NODE
	// last_node->next->NULL
	// last_node->next->HEAD
	current_to_change = *stack;
	current = *stack;
	i = 0;
	while (current->next != NULL)
	{
		if (i == len_stack - 1)
			current->next = current_to_change;
		i++;
		current = current->next;
	}
	// update 
}
