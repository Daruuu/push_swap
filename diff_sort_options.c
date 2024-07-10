/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_sort_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/10 21:30:13 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Case: 2 1 3 => 1 2 3	swap first two
void	sort_stack_three_numbers(t_stack **stack_a)
{
	t_node	*f;
	t_node	*s;
	t_node	*t;

	f = (*stack_a)->head;
	s = f->next;
	t = s->next;
	if (f->data > s->data && f->data < t->data)
		sa(*stack_a);
	else if (f->data > s->data && s->data > t->data)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (f->data > s->data && s->data < t->data && f->data > t->data)
		ra(stack_a);
	else if (f->data < s->data && s->data < t->data && f->data < t->data)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	else if (f->data < s->data && s->data > t->data && f->data > t->data)
		rra(stack_a);
}

/*
void	sort_stack_five_numbers(t_stack **stack_a)
{

}
void	sort_stack_ten_numbers(t_stack **stack_a)
{
}
*/

//t_stack	*handle_sort_options(t_stack *stack, int len_stack, t_stack *stack_b)
t_stack	*handle_sort_options(t_stack **stack, int len_stack)
{

	if (!stack)
		return (NULL);
	if (len_stack == 3)
		sort_stack_three_numbers(&*stack);
	return (*stack);
}
	/*
	else if (length_stack == 5)
		sort_stack_five_numbers(&stack);
	*/
