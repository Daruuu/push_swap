/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/08 23:36:58 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_with_split(char **av);

void	check_all_validations(int ac, char **av)
{
	if (has_invalid_characters(ac, av))
	{
		ft_printf("Error invalid char\n");
		exit(EXIT_FAILURE);
	}
	else if (has_duplicated_numbers(ac, av))
	{
		ft_printf("Error duplicate number\n");
		exit(EXIT_FAILURE);
	}
	else if (if_numbers_are_sorted(ac, av))
	{
		ft_printf("numbers sorted\n");
		exit(EXIT_SUCCESS);
	}
}

void	input_check_argc(int ac, char **av)
{
	t_stack	*new_stack;
	char	**split_av;
	int		count_split;

	if (ac < 2)
	{
		ft_printf("ac incorrect!\n");
		return ;
	}
	new_stack = (t_stack *) malloc(sizeof(t_stack));
	if (!new_stack)
		free_stack(new_stack);
	if (ac == 2)
	{
		count_split = 0;
		split_av = ft_split(av[1], ' ');	//TODO: error with SPLIT
		while (split_av[count_split])
			count_split++;
		ft_printf("%d\n", count_split);	//LOGGGGGGGGGGGGG
		check_all_validations(count_split, split_av);
		new_stack = init_stack(count_split, split_av);
		free_split(split_av);
	}
	else
	{
		check_all_validations(ac - 1, av + 1);
		//new_stack = init_stack(ac, av);
	}
	if (new_stack)
	{
		print_stack(new_stack);
		free_stack(new_stack);
	}
}
