/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:27:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/29 18:20:43 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:58:37 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/29 14:49:03 by dasalaza		  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
		t_stack	*stack_b;
	char	**new_arg;
	int		len_new_ac;

	stack_a = NULL;
	stack_b = NULL;
	new_arg = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		new_arg = ft_split(av[1], ' ');
		if (!new_arg)
			return (1);
		len_new_ac = 0;
		while (new_arg[len_new_ac])
			len_new_ac ++;
		ac = len_new_ac;
	}
	input_check_argc(ac, av);

	stack_a = init_stack(ac, av);
//	set_index_stack(stack_a);
//
//	int chunk_size = stack_a->len / 4;
//	int chunk_multiplier = 1;
//	best_move_in_node_actual(stack_a, chunk_size * chunk_multiplier);
//	chunk_multiplier = 2;
//	best_move_in_node_actual(stack_a, chunk_size * chunk_multiplier);

	stack_b = init_stack_empty();
//	ft_printf("LENGTH OF STACK A: %d \n", ft_size_stack(stack_a));

	set_index_stack(stack_a);

	//ft_printf("STACK WITH INDEX:\n");
	// print_stack(stack_a);

	handle_sort_options(&stack_a, &stack_b, stack_a->len);


//	ft_printf(" finall hereeeeee\n");
//	print_stacks(stack_a, stack_b);
	free_allocs(ac, stack_a, stack_b, new_arg);
	return (0);
}
