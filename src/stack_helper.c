/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:13:56 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/30 12:41:46 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_index_stack(t_stack *stack)
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
	while (current != NULL)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = index;
		}
		index++;
		current = current->next;
	}
	return (min_index);
}

t_node	*get_tail_of_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_node	*get_before_last_node_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL || stack->len < 2)
		return (NULL);
	current = stack->head;
	while (current->next->next != NULL)
		current = current->next;
	return (current);
}

t_node	*create_new_node(char **av, int i)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		free_node(new_node);
	new_node->data = ft_atoll(av[i]);
	new_node->index = 0;
	new_node->previous = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*set_stack_null(t_stack *stack)
{
	stack->len = 0;
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}
