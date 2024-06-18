/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:35:34 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/18 15:14:19 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ROTATE FIRST ELEMENT OF STACK TO LAST POSITION 
 * |HEAD|-> |1|next| --> |prev|2|next|--> |prev|3|next| --> |prev|4|next| --> NULL
 *
 * |prev|2|next|--> |prev|3|next| --> |prev|4|next| --> |prev|1|next| --> NULL 
*/
void	rotate_a(t_node **stack)
{
	// encontrar el ultimo nodo del STACK
	// TODO: function to continue !!!
	int	len_stack;

	len_stack = ft_size_stack(*stack);
	

}
