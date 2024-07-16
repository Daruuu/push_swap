/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:57:52 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/16 11:10:42 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack;
	t_node	*new_node;
	int		i;

	stack = (t_stack *) malloc(sizeof(t_stack));
	is_stack_null(stack);
	stack = set_stack_null(stack);
	i = 0;
	while (++i < ac)
	{
		new_node = create_new_node(av, i);
		if (stack->head == NULL)
		{
			stack->head = new_node;
			stack->tail = new_node;
		}
		else
		{
			stack->tail->next = new_node;
			new_node->previous = stack->tail;
			stack->tail = new_node;
		}
		stack->len++;
	}
	return (stack);
}

t_stack	*init_stack_empty(void)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	stack = set_stack_null(stack);
	return (stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;
	int		i;

	if (!stack)
		return ;
	current = stack->head;
	i = 1;
	while (current != NULL)
	{
		//printf("[%d]->%d\n", i, current->data);
		ft_printf("%d ", current->data);
		i++;
		current = current->next;
	}
	ft_printf("\n");
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
