/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/18 13:53:21 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * function to order each chunk
*/

void	sort_stack_with_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	total_chunks;
	int	i;
	int	j;
	int	min_value;
	int	max_value;

	//redondear cada chunk hacia arriba
	total_chunks = stack_a->len + chunk_size - 1;
	i = 0;
	while (i < total_chunks)
	{
		min_value = min_index_stack(stack_a);
		max_value = max_index_stack(stack_a);
		j = 0;
		while (j < stack_a->len)
		{
			j++;
		}
		i++;
	}
}

/*
//	Función para dividir el stack en chunks y ordenar
void sort_stack_with_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int total_chunks = (stack_a->len + chunk_size - 1) / chunk_size; // redondea hacia arriba
	int min_value, max_value;
	for (int i = 0; i < total_chunks; i++)
	{
		min_value = find_min_value(stack_a);
		max_value = find_max_value(stack_a);
		// Mueve elementos dentro del rango del chunk a stack_b
		for (int j = 0; j < stack_a->len; j++)
		{
			if (stack_a->head->data >= min_value && stack_a->head->data <= max_value)
				push_b(&stack_a, &stack_b);
			else
				ra(&stack_a);
		}
		// Mueve elementos de stack_b de vuelta a stack_a
		while (stack_b->len > 0)
			push_a(&stack_b, &stack_a);
	}
}
*/
