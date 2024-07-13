/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_sort_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:42:06 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/13 15:38:16 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Case: 2 1 3 => 1 2 3	swap first two
/*
 * 3 2 1: sa(*stack_a); rra(stack_a);	ERROR	
 * 3 1 2: ra(stack_a);					OK
 * 2 3 1: rra(stack_a);					ERROR
 * 2 1 3: sa(*stack_a);					OK
 * 1 3 2: sa(*stack_a); ra(stack_a);	OK
 * 1 2 3; sorted
*/

void	sort_stack_three_numbers(t_stack **stack_a)
{
	t_node	*f;
	t_node	*s;
	t_node	*t;

	f = (*stack_a)->head;
	s = f->next;
	t = s->next;
	if (f->data > s->data && f->data > t->data && s->data > t->data)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (f->data > s->data && f->data > t->data && s->data < t->data)
		ra(stack_a);
	else if (f->data > s->data && f->data < t->data)
		sa(*stack_a);
	else if (f->data < s->data && f->data > t->data)
		rra(stack_a);
	else if (f->data < s->data && s->data > t->data)
	{
		sa(*stack_a);
		ra(stack_a);
	}
}

//void	sort_stack_five_numbers(t_stack **stack_a)
/*
 *	move the 2 first number from STACK A to STACK B
 *	use logic from 3 random numbers to sort in STACK A
 *	MAX MOVEMENTS Is 12
 *	Mover los 2 números más pequeños a la pila B.
 *	Ordenar los 3 números restantes en A usando la función anterior.
 *	Mover los 2 números de B de vuelta a A y colocarlos en la posición correcta.
*/
void	sort_stack_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int	min_position;

	if (*stack_a == NULL)
		return ;
	while ((*stack_a)->len > 3)
	{
		min_position = find_min_node_position(*stack_a);
		if (min_position <= ((*stack_a)->len / 2))
		{
			while (min_position--)
				ra(stack_a);
		}
		else
		{
			min_position = (*stack_a)->len - min_position;
			while (min_position--)
				rra(stack_a);
		}
		push_b(stack_a, stack_b);
	}
	sort_stack_three_numbers(&(*stack_a));
	while (*stack_b)
		push_a(stack_a, stack_b);
	if ((*stack_a)->head->data > (*stack_a)->head->next->data)
		sa(*stack_a);
}

t_stack	*handle_sort_options(t_stack **sa, t_stack **sb, int len_stack)
{
	if (!sa)
		return (NULL);
	if (len_stack == 3)
		sort_stack_three_numbers(&*sa);
	else if (len_stack == 5)
		sort_stack_five_numbers(&*sa, &*sb);
	return (*sa);
}
