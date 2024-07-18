/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:50:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/18 19:32:51 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index_chunk(t_stack *stack, int len_chunk)
{
	int		min;
	int		index;
	int		min_index;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (0);
	current = stack->head;
	min = current->data;
	index = 0;
	min_index = index;
	while (current != NULL && stack->len != len_chunk - 1)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = index;
		}
		index++;
		current = current->next;
		len_chunk++;
	}
	return (min_index);
}

/*
 * function to order each chunk
 * redondear cada chunk hacia arriba
 * 2 4 20 19 15 1 9 13 10 11 16 3 8 14 12 18 7 17 6 5
 * chunk 1:	2 4 20 19 15 
 * chunk 2:	1 9 13 10 11 
 * chunk 3:	16 3 8 14 12
 * chunk 4:	18 7 17 6 5
*/

void	sort_stack_with_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	i;
	int	j;
	int	min_value_chunk;
	int	max_value_chunk;

	i = 0;
	while (i < stack_a->len)
	{
		j = 0;
		while (j < chunk_size)
		{
			//	chunk 1:	2 4 20 19 15 
			min_value_chunk = min_index_chunk(stack_a, chunk_size);	//	2
			max_value_chunk = max_index_stack(stack_a);	//	20	
			ft_printf("%d\n", min_value_chunk);
			ft_printf("%d\n", max_index_stack);
			if (stack_a->head->data >= min_value_chunk
					&& stack_a->head->data <= max_value_chunk)
				push_b(&stack_a, &stack_b);
			else
				ra(&stack_a);
			j++;
		}
		i++;
	}
}

int	max_index_chunk(t_stack *stack, int chunk_size)
{
	int		max;
	int		index;
	int		max_index;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (0);
	current = stack->head;
	max = current->data;
	index = 0;
	max_index = index;
	while (current != NULL && stack->len != chunk_size)
	{
		if (current->data > max)
		{
			max = current->data;
			max_index = index;
		}
		index++;
		current = current->next;
	}
	return (max_index);
}
