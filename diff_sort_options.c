/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_sort_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/16 20:27:46 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	aux_sort_five_numbers(t_stack *stack_a);

//	Case: 2 1 3 => 1 2 3	swap first two
/*
 * 3 2 1: sa(*stack_a); rra(stack_a);	OK	
 * 3 1 2: ra(stack_a);					OK
 * 2 3 1: rra(stack_a);					OK
 * 2 1 3: sa(*stack_a);					OK
 * 1 3 2: sa(*stack_a); ra(stack_a);	OK
 * 1 2 3; sorted
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

/*
	if (f->data > s->data && f->data > t->data)
	{
		sa(stack_a);
		rra(&stack_a);
	}
	else if (f->data > s->data && f->data > t->data && s->data < t->data)
		ra(&stack_a);
	else if (f->data > s->data && f->data < t->data)
		sa(stack_a);
	else if (f->data < s->data && f->data < t->data && s->data > t->data)
	{
		sa(stack_a);
		ra(&stack_a);
	}
	else if (f->data < s->data && f->data > t->data)
		ra(&stack_a);
*/
/*
 *	Step 1: Push 3 to stack B (Max 3 moves)
 *	Step 2: Sort stack A (Max 2 moves)
 *	Step 3: Push 3 to stack A (1 move)
 *	Step 4: Rotate stack A (1 move)
 *	Maximum number of moves = 7 moves
 *	
*/

void	sort_stack_four_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int		max_pos;

	max_pos = max_num_in_stack(stack_a);
	ft_printf("max posi :%d\n", max_pos);
	if (max_pos <= stack_a->len / 2)
	{
		while (max_pos-- > 0)
			ra(&stack_a);
	}
	else
	{
		max_pos = stack_a->len - max_pos;
		while (max_pos-- > 0)
			rra(&stack_a);
	}
	push_b(&stack_a, &stack_b);
	sort_stack_three_numbers(stack_a);
	push_a(&stack_b, &stack_a);
	if (stack_a->head->data > stack_a->head->next->data)
		rra(&stack_a);
}

/*
 *	move the 2 min number from STACK A to STACK B
 *	use logic from 3 random numbers to sort in STACK A
 *	Move 2 numbers to B and return A and set in correct position
 *	MAX MOVEMENTS Is 12
*/

void	sort_stack_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	while (stack_a->len > 3)
	{
		min_pos = find_min_node_position(stack_a);
		if (min_pos <= stack_a->len / 2)
		{
			while (min_pos-- > 0)
				ra(&stack_a);
		}
		else
		{
			min_pos = stack_a->len - min_pos;
			while (min_pos-- > 0)
				rra(&stack_a);
		}
		push_b(&stack_a, &stack_b);
	}
	sort_stack_three_numbers(stack_a);
	while (stack_b->len > 0)
		push_a(&stack_b, &stack_a);
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
	return (*sa);
}
