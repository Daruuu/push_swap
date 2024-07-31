/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/31 15:00:25 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_all_validations(int ac, char **av)
{
	if (has_invalid_characters(ac, av))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (has_duplicated_numbers(ac, av))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (if_numbers_are_sorted(ac, av))
		exit(EXIT_SUCCESS);
	else if (number_out_of_range(ac, av))
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	input_check_argc(int ac, char **av)
{
	check_all_validations(ac , av + 1);
}
