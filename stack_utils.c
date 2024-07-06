/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:57:52 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/06 19:48:40 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	t_node	*new_node;
	t_node	*current;
	int		i;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack = set_stack_null(stack);
	i = 0;	//	av++;
	while (++i < ac)
	{
		new_node = create_new_node(av, i);
		if (stack->head == NULL)
			stack->head = new_node;
		else
		{
			current = stack->tail;
			current->next = new_node;
			new_node->previous = current;
			stack->tail = new_node;
		}
		stack->len++;
	}
	return (stack);
}

void	print_stack(t_node *stack)
{
	t_node	*current;
	int		i;

	if (!stack)
		return ;
	current = stack;
	i = 0;
	while (current != NULL)
	{
		printf("[%d]->%d\n", i, current->data);
		i++;
		current = current->next;
	}
}

/*	Set indexes in STACK
 *	TODO: redo this functions with others variables names
*/
void	set_index_stack(t_node **head_ref)
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
			if (others->data < current->data)
				new_index ++;
			others = others->next;
		}
		current->index = new_index;
		others = *head_ref;
		current = current->next;
	}
}

int	ft_size_stack(t_stack *stack)
{
	int		i;
	t_node	*current_node;

	current_node = stack->head;
	i = 0;
	while (current_node != NULL)
	{
		i++;
		current_node = current_node->next;
	}
	stack->len = i;
	return (i);
}

/*
 * function if input list are sorted,
 * finish the program 
*/

int	stack_is_sorted(t_stack *stack_a)
{
	t_node	*current;

	if (stack_a == NULL || stack_a->head == NULL)
		return (EXIT_FAILURE);
	current = stack_a->head;
	while (current != NULL)
	{
		if (current->data > current->next->data)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

/*
t_stack *init_stack(int ac, char **av)
{
    t_stack *stack;
    t_node *new_node;
    t_node *current;
    int i;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->len = 0;
    stack->head = NULL;
    stack->tail = NULL;

    for (i = 1; i < ac; i++)
    {
        new_node = (t_node *)malloc(sizeof(t_node));
        if (!new_node)
            return (NULL); 
        new_node->data = ft_atoi(av[i]);
        new_node->index = 0;  // Esto puede ser actualizado después
        new_node->previous = NULL;
        new_node->next = NULL;

        if (stack->head == NULL)
        {
            stack->head = new_node;
            stack->tail = new_node;
        }
        else
        {
            current = stack->tail;
            current->next = new_node;
            new_node->previous = current;
            stack->tail = new_node;
        }
        stack->len++;
    }
    return stack;
}
*/
