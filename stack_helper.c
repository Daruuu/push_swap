/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:13:56 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/06 21:56:22 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * get the last before node in stack
*/

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

/*
 * get last NODE of stack
*/

t_node	*get_tail_of_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	if (current == NULL)
		return (NULL);
	while (current->next != NULL)
		current= current->next;
	return (current);
}

t_node	*create_new_node(char **av, int i)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		free_node(new_node);
	new_node->data = ft_atoi(av[i]);
	new_node->index = i;
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

t_stack	*stack_with_split(char **av)
{
	int		i;
	t_stack	*new_stack;
	char	**split_av;

	split_av = ft_split(av[1], ' ');
	while (split_av[i] != NULL)
		i++;
	new_stack = (t_stack *) malloc(sizeof(t_stack));
	if (!new_stack)
		free_stack(new_stack);
	new_stack = init_stack(i, split_av);
	return (new_stack);
}

