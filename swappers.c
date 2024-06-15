/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:01:03 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/16 00:22:19 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Set indexes in STACK*/
void	set_index_in_stack(t_node **head_ref)
{
	t_node	*current;
	t_node	*others;
	int		new_index;

	current = *head_ref;
	others = current;
	while (current)
	{
		new_index = 0;
		while (others)
		{
			if (others->value < current->value)
				new_index++;
			others = others->next;
		}
		current->index = new_index;
		others = *head_ref;
		current = current->next;
	}
}

/* SWAP DATA AND INDEX OF NODES*/
void	swap_nodes(t_node *stack)
{
	int	temp_data;
	int	temp_index;

	if (stack == NULL || stack->next == NULL)
		return ;
	// update value
	temp_data = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp_data;
	// UPDATE INDEX;
	temp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp_index;
}

/*
 * function if input list are sorted,
 * finish the program 
*/
/*
void	if_stack_is_sorted_two_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[1][i] != '\0')
	{
	}
}

int	if_stack_is_sorted_x_args(int ac, char *av)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
*/

/*
void	sort_stack_per_value(t_node **head_ref)
 {
 	t_node	*sort_stack;
 	t_node	*current_node;
 	t_node	*next_node;
 	t_node	*tmp;

 	if (head_ref == NULL || *head_ref == NULL )
 		return ;
 	sort_stack = NULL;
 	current_node = *head_ref;
 	while (current_node != NULL)
 	{
 		next_node = current_node->next;
 		if (sort_stack == NULL || sort_stack->value > current_node->value)
 		{
 			current_node->next = sort_stack;
 			current_node->previous = NULL;
 			if (sort_stack != NULL)
 				sort_stack->previous = current_node;
 			sort_stack = current_node;
 		}
 		else
 		{
 			tmp = sort_stack;
 			while (tmp->next != NULL && tmp->next->value < current_node->value)
 				tmp = tmp->next;
 			current_node->next = tmp->next;
 			if (tmp->next != NULL)
 				tmp->next->previous = current_node;
 			tmp->next = current_node;
 			current_node->previous = tmp;
 		}
 		current_node = next_node;
 	}
 	*head_ref = sort_stack;
}
*/
