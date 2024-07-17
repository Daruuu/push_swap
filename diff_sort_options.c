/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_sort_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/17 15:53:40 by dasalaza         ###   ########.fr       */
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


//	flota el max number de un stack de 4 numbers
void	float_min_number_four_stack(t_stack *stack_a)
{
	int		min_pos;

	min_pos = min_index_stack(stack_a);
	if (min_pos == 1)
		sa(stack_a);
	else if (min_pos == 2)
	{
		rra(&stack_a);
		rra(&stack_a);
	}
	else if (min_pos == 3)
		rra(&stack_a);
}

void	sort_stack_four_numbers(t_stack *stack_a, t_stack *stack_b)
{
	float_min_number_four_stack(stack_a);
	push_b(&stack_a, &stack_b);
	sort_stack_three_numbers(stack_a);
	push_a(&stack_b, &stack_a);
}

/*
 *	move the 2 min number from STACK A to STACK B
 *	use logic from 3 random numbers to sort in STACK A
 *	Move 2 numbers to B and return A and set in correct position
 *	MAX MOVEMENTS Is 12
*/

void	float_min_number_five_stack(t_stack *stack_a)
{
	int		min_pos;

	min_pos = min_index_stack(stack_a);
	if (min_pos == 1)
		sa(stack_a);
	else if (min_pos ==  2)
	{
		ra(&stack_a);
		ra(&stack_a);
	}
	else if (min_pos ==  3)
	{
		rra(&stack_a);
		rra(&stack_a);
	}
	else if (min_pos == 4)
		rra(&stack_a);
}

void	sort_stack_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	float_min_number_five_stack(stack_a);
	push_b(&stack_a, &stack_b);
	sort_stack_four_numbers(stack_a, stack_b);
	push_a(&stack_b, &stack_a);
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