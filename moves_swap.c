/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:43:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/12 17:51:36 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	*tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}

/*
 * 1	2
 * 2	1
 * 3	3
*/

void	swap_a(t_stack *head)
{
	ft_swap(head->value, head->)

}
