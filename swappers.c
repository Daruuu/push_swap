/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:01:03 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/27 21:24:37 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * function to order stack in order of value
*/
t_stack	order_stack_by_index(t_node *stack_a)
{
	int	len_list;
	int	i;

	len_list = ft_lst_size(stack_a);
	while (i < len_list) 
	{
		i++;
	}

	return (0);
}

void	ft_swap (int *a, int *b)
{
	int	*tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

void	swap_nodes(t_node *node_a, t_node *node_b)
{
	int	tempValue;
	int	tempIndex;

	tempValue = node_a->value;
	tempIndex = node_a->index;
	node_a->index = node_b->index;
	node_a->value = node_b->value;
	node_b->index = tempIndex;
	node_b->value = tempValue;
}

/*
 * function if input ist are sorted, finish the program 
*/
void	if_stack_is_sorted(t_stack *stack_input)
{


}
