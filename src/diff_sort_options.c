/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_sort_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:27:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/30 00:44:17 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_sort_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/29 14:38:02 by dasalaza 		  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	int	chunk_size;
	int	size_sa;

	size_sa = ft_size_stack(stack_a);
	if (size_sa <= CASE_HUNDRED)
		chunk_size = size_sa / 4;
	else
		chunk_size = size_sa / 8;
	move_chunks_from_a_to_b(stack_a, stack_b, chunk_size);
	move_chunks_from_b_to_a(stack_a, stack_b);
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
