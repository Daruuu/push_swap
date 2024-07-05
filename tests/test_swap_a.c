/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:20:27 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/05 11:40:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	//int result = ft_size_stack(stack_a);
	
	//	1, 6, 4, -1, 27
	//	printf("%d\n", result);
	printf("ITERATE LISTA:\n");
	iterate_stack(stack_a->head);

	printf("EXECUTE SWAP_A IN STACK:\n");
	swap_a(stack_a->head);
	printf("PRINT STACK:\n");
	iterate_stack(stack_a->head);


	//printf("%i\n", stack_a->head->next->next->data);
	//printf("%d\n", stack_a->head->next->data);

	return (0);
}
