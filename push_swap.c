/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:27:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/31 15:37:08 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**new_arg;

	stack_a = NULL;
	stack_b = NULL;
	new_arg = NULL;
	if (ac < 2)
		return (0);
	input_check_argc(ac, av);
	stack_a = init_stack(ac, av);
	stack_b = init_stack_empty();
	set_index_stack(stack_a);
	handle_sort_options(&stack_a, &stack_b, stack_a->len);
//	print_stacks(stack_a, stack_b);
	free_allocs(ac, stack_a, stack_b, new_arg);
	return (0);
}
