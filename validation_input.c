/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:56:58 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/12 16:06:23 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * CASE 1:
 * ./push_swap " 1 3 5 -11"
 *
 * CASE 2:
 * ./push_swap 1 3 5 -11
 *
 * CASE 3:
 * ./push_swap " 1 3 5 -11"
 */
void	quantity_of_arguments(int ac, char **av)
{
	/* utilizar atoi*/
	if (ac == 2)
	{
	}
	else if (ac > 2)
	{
	}
	else
		ft_printf("error args!\n");
}
