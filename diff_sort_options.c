/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_sort_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/09 19:32:40 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_three_numbers(t_stack **stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = (*stack_a)->head;
	second = first->next;
	third = second->next;
	if (first->data > second->data && first->data < third->data)
		//	Case: 2 1 3 => 1 2 3	swap first two
		swap_a(*stack_a);
	else if ()

}

/*
void	sort_stack_five_numbers(t_stack **stack_a)
{

}
void	sort_stack_ten_numbers(t_stack **stack_a)
{
}

void	ft_select_input(void)
{
}
*/
/*
 * diff cases of input and call functions 3, 5 , x
*/
t_stack	*handle_sort_options_stack(t_stack *stack, int length_stack)
{
	if (!stack)
		return (NULL);
	if (length_stack == 3)
		sort_stack_three_numbers(&stack);
	else if (length_stack == 5)
		sort_stack_five_numbers(&stack);
	return (stack);
}
