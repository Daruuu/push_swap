/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/01 20:15:30 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ROTATE FIRST ELEMENT OF STACK TO LAST POSITION 
 * |HEAD|-> |1|next| --> |prev|2|next|--> |prev|3|next| --> |prev|4|next| --> NULL
 *
 * |prev|2|next|--> |prev|3|next| --> |prev|4|next| --> |prev|1|next| --> NULL 
*/
// TODO: function to continue !!!
void	rotate_a(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack == NULL || stack->len < 2)
		return ;
	// inicializar los punteros al primer y ultimo nodo
	first = stack->head;
	last = stack->tail;
	// desvincular el primer NODO al funal de la pila
	stack->head = first->next; 
	stack->head->previous = NULL;
	//recolorcar el primer nodo al funal de la pila
	/*
	last->next = first;
	first->previous = last;
	first->next = NULL;
	stack->tail = first;	
	*/

}
