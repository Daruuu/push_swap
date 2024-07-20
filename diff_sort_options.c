/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_sort_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/20 15:56:44 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * 3 2 1: sa(*stack_a); rra(stack_a);	OK	
 * 3 1 2: ra(stack_a);					OK
 * 2 3 1: rra(stack_a);					OK
 * 2 1 3: sa(*stack_a);					OK
 * 1 3 2: sa(*stack_a); ra(stack_a);	OK
*/

void	sort_stack_three_numbers(t_stack *stack_a)
{
	t_node	*f;
	t_node	*s;
	t_node	*t;

	f = stack_a->head;
	s = f->next;
	t = s->next;
	if (f->data > s->data && f->data > t->data && s->data > t->data)
	{
		sa(stack_a);
		rra(&stack_a);
	}
	else if (f->data > s->data && f->data > t->data && s->data < t->data)
		ra(&stack_a);
	else if (f->data > s->data && f->data < t->data)
		sa(stack_a);
	else if (f->data < s->data && f->data > t->data)
		rra(&stack_a);
	else if (f->data < s->data && s->data > t->data)
	{
		sa(stack_a);
		ra(&stack_a);
	}
}

void	sort_stack_four_numbers(t_stack *stack_a, t_stack *stack_b)
{
	float_min_number_four_stack(stack_a);
	push_b(&stack_a, &stack_b);
	sort_stack_three_numbers(stack_a);
	push_a(&stack_b, &stack_a);
}

void	sort_stack_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	float_min_number_five_stack(stack_a);
	push_b(&stack_a, &stack_b);
	sort_stack_four_numbers(stack_a, stack_b);
	push_a(&stack_b, &stack_a);
}

void	sort_with_chunks(t_stack *stack_a, t_stack *stack_b)
{
	int	size_sa;
	int	size_sb;
	int	max_case;

	max_case = 100;
//	size_sa = stack_a->len;
	size_sa = ft_size_stack(stack_a);
	ft_printf("SIZE STACK A: %d \n", size_sa);
	ft_printf("SIZE STACK B: %d \n", size_sb);
	if (size_sa >= max_case)
		move_nodes_from_a_to_b(stack_a, stack_b, size_sa / 8);
	else
		move_nodes_from_a_to_b(stack_a, stack_b, size_sa / 4);
	size_sb = ft_size_stack(stack_b);
	if (size_sb >= max_case)
		move_nodes_from_b_to_a(stack_a, stack_b);
	else
		move_nodes_from_b_to_a(stack_a, stack_b);
	if (stack_is_sorted_by_index(stack_a) == 0)
		sa(stack_a);
}

t_stack	*handle_sort_options(t_stack **sa, t_stack **sb, int len_stack)
{
	if (!sa)
		return (NULL);
	if (len_stack == 3)
		sort_stack_three_numbers(*sa);
	else if (len_stack == 4)
		sort_stack_four_numbers(*sa, *sb);
	else if (len_stack == 5)
		sort_stack_five_numbers(*sa, *sb);
	else
		sort_with_chunks(*sa, *sb);
	return (*sa);
}
/*
else if (len_stack <= 100)
	sort_stack_chunks(*sa, *sb, len_stack / 4);
else if (len_stack <= 500)
	sort_stack_chunks(*sa, *sb, len_stack / 7);
*/
