/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_erros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:30:52 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/06 21:47:27 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_each_node(t_stack **stack)
{
	t_node	*current;
	t_node	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	current = (*stack)->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stack);
	*stack = NULL;
}

void	free_node(t_node *node)
{
	if (node)
		free(node);
	node = NULL;
}

void	free_split(char **split)
{
	int	i;

	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
