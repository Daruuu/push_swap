/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:13:56 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/17 17:32:41 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_min_node_position(t_stack *stack)
{
	t_node	*current;
	t_node	*min_node;
	int		i;
	int		min_position;

	if (stack == NULL || stack->len == 0)
		return (0);
	i = 0;
	current = stack->head;
	min_node = stack->head;
	while (current != NULL)
	{
		if (current->data < min_node->data)
		{
			min_node = current;
			min_position = i;
		}
		i++;
		current = current->next;
	}
	return (min_position);
}

//	return la posicion del nodo con el numero minimo
//	los indices empiezan en 0 y terminan en stack->len - 1

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
/*
int	max_num_in_stack(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (0);
	current = stack->head;
	max = current->data;
	while (current != NULL)
	{
		if(current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}
*/

/*
int	max_num_in_stack(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (stack == NULL || stack->head == NULL)
		return (0);
	current = stack->head;
	max = current->data;
	while (current != NULL)
	{
		if(current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}
*/
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
	i = 0;
	while (split_av[i] != NULL)
		i++;
	check_all_validations(i, split_av);
	new_stack = init_stack(i, split_av);
	free_split(split_av);
	return (new_stack);
}
