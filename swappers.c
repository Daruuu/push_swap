/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:01:03 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/17 23:05:53 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* */
/*
void	set_index_in_stack(t_node **head_ref)
{
}
*/
/* SWAP DATA AND INDEX OF NODES*/
void	swap_nodes(t_node *stack)
{
	int	temp_data;
	int	temp_index;

	if (stack == NULL || stack->next == NULL)
		return ;
	/* update value*/
	temp_data = stack->data;
	stack->data = stack->next->data;
	stack->next->data= temp_data;
	/* UPDATE INDEX */
	temp_index = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp_index;
}

void	swap_a(t_node *stack_a)
{
	swap_nodes(stack_a);
}

int	main(void)
{
	t_stack	*stack_a;

	stack_a = (t_stack *) malloc(sizeof(t_stack));
	if (!stack_a)
		return (1);
	stack_a->head = NULL;
	
	t_node	*node01;
	t_node	*node02;
	t_node	*node03;
	t_node	*node04;
	t_node	*node05;

	node01 = (t_node *) malloc(sizeof(t_node));
	node02 = (t_node *) malloc(sizeof(t_node));
	node03 = (t_node *) malloc(sizeof(t_node));
	node04 = (t_node *) malloc(sizeof(t_node));
	node05 = (t_node *) malloc(sizeof(t_node));

	node01->data = 1;
	node01->next = NULL;
	
	node02->data = 6;
	node02->next = NULL;

	node03->data = 4;
	node03->next = NULL;

	node04->data = -1;
	node04->next = NULL;

	node05->data = 27;
	node05->next = NULL;
	
	stack_a->head = node01;

	node01->next = node02;
	node02->next = node03;
	node03->next = node04;
	node04->next = node05;
	int result = ft_size_stack(stack_a);
	
	printf("%d\n", result);
	swap_a(stack_a->head);
	printf("%i\n", stack_a->head->next->next);
	printf("%d\n", stack_a->next->data);

	return (0);
}

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
