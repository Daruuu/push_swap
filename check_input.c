/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/26 20:21:13 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_range_number(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
			return (1);
	}
	return (0);
}

void	check_all_input(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc < 2)
		write(1, "error argc\n", 11);
	else
	{
		if (!(check_range_number(argv) && check_duplicate_number(argc, argv)))
		{
			write(1, "error check\n", 12);
			exit(EXIT_FAILURE);
		}
		else
			write(1, "valid input\n", 12);
	}
}
