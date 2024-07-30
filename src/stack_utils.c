/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:57:52 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/30 12:44:03 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		i;

	current_a = stack_a ? stack_a->head : NULL;
	current_b = stack_b ? stack_b->head : NULL;
	ft_printf("%s\t\t\t%s\n", "Stack A", "Stack B");
	ft_printf("%s\t\t\t%s\n", "-------", "-------");
	i = 1;
	while (current_a != NULL || current_b != NULL)
	{
		if (current_a != NULL)
		{
			ft_printf("[%d]-> %d", current_a->index, current_a->data);
			current_a = current_a->next;
		}
		else
			ft_printf("[xx]-> xxxx");
		ft_printf("\t\t\t");
		if (current_b != NULL)
		{
			ft_printf("[%d]-> %d", current_b->index, current_b->data);
			current_b = current_b->next;
		}
		else
			ft_printf("[xx]-> xxxx");
		ft_printf("\n");
		i++;
	}
	if (stack_a == NULL)
		ft_printf("Stack A empty!\n");
	if (stack_b == NULL)
		ft_printf("Stack B empty!\n");
}
*/