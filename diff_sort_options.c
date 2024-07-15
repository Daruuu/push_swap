/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_sort_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/16 01:02:33 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	aux_sort_five_numbers(t_stack *stack_a);

//	Case: 2 1 3 => 1 2 3	swap first two
/*
 * 3 2 1: sa(*stack_a); rra(stack_a);	ERROR	
 * 3 1 2: ra(stack_a);					OK
 * 2 3 1: rra(stack_a);					ERROR
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

//void	sort_stack_five_numbers(t_stack **stack_a)
/*
 *	move the 2 first number from STACK A to STACK B
 *	use logic from 3 random numbers to sort in STACK A
 *	Mover los 2 números de B de vuelta a A y colocarlos en la posición correcta.
 *	MAX MOVEMENTS Is 12
*/
void	sort_stack_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->len > 3)
	{
		aux_sort_five_numbers(*stack_a);
		push_b(stack_a, stack_b);
	}
	sort_stack_three_numbers(*stack_a);
	while ((*stack_b)->head != NULL)
		push_a(stack_b, stack_a);
}

void	aux_sort_five_numbers(t_stack *stack_a)
{
	t_node	*current;
	int		max_node;
	int		i;

	current = stack_a->head;
	max_node = max_num_in_stack(stack_a);
	i = 0;
	while (current != NULL)
	{
		if (current->data == max_node)
			break ;
		current = current->next;
		i++;
	}
	if (i <= (stack_a->len / 2))
	{
		while (i > 0)
		{
			ra(&stack_a);
			i--;
		}
	}
	else
	{
		i = stack_a->len - i;
		while (i > 0)
		{
			rra(&stack_a);
			i--;
		}
	}
}

t_stack	*handle_sort_options(t_stack **sa, t_stack **sb, int len_stack)
{
	if (!sa)
		return (NULL);
	if (len_stack == 3)
		sort_stack_three_numbers(*sa);
	else if (len_stack == 5)
		sort_stack_five_numbers(sa, sb);
	return (*sa);
}
/*
	ft_printf("stack A: ");
	print_stack(*stack_a);
	ft_printf("stack B: ");
	print_stack(*stack_b);

	sort_stack_three_numbers(&(*stack_b));

	//	push A
	//	push_a(&*stack_b, &*stack_a);
	//	ft_printf("stack A with push_a: ");
	//	print_stack(*stack_a);
*/
