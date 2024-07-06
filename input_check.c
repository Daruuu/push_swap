/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/06 23:50:46 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_with_split(char **av);

void	check_all_validations(int ac, char **av)
{
	if (has_invalid_characters(ac, av))
		ft_printf("Error invalid char\n");
	else if (has_duplicated_numbers(ac, av))
		ft_printf("Error duplicate number\n");
	else if (if_numbers_are_sorted(ac, av))
		ft_printf("numbers sorted\n");
}

void	input_check_argc(int ac, char **av)
{
	t_stack	*new_stack;

	if (ac < 2)
		ft_printf("ac incorrect!\n");
	new_stack = (t_stack *) malloc(sizeof(t_stack));
	if (!new_stack)
		free_stack(new_stack);
	if (ac == 2)
	{
		check_all_validations(ac, av);
		new_stack = stack_with_split(av);	
	}
	if (ac > 2)
	{
		check_all_validations(ac, av);
		new_stack = stack_with_split(av);
	}
}
