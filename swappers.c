/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:01:03 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/26 03:39:06 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * function to swap positions of stack in order of value
*/

/*
t_stack	order_stack_by_index(t_node *stack_a)
{
	t_stack	stack_update;
	int	len_list;
	int	i;

	len_list = ft_lst_size(stack_a);
	while (i < len_list) 
	{
		if (ft_swap(stack_a->value, stack_a))
		{

		}

	}

	return (stack_update);
}
*/

/*
 * swap integers
*/
void	ft_swap (int *a, int *b)
{
	int	*tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}
