/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:02:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/03 13:14:50 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (1);
}

static int	has_invalid_characters(int count, char **av)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_valid_number(av[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
/*
 * 1 4 5 11 -1
*/

static int	has_duplicated_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

static int	if_numbers_are_sorted(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	check_all_inputs(int ac, char **av)
{
	char	**args;
	int		count;

	if (ac < 2)
	{
		ft_printf("error argc\n");
		exit (EXIT_FAILURE);
	}
	args = split_arguments(ac, av, &count);
	if (has_invalid_characters(count, args))
	{
		ft_printf("invalid character\n");
		exit(EXIT_FAILURE);
	}
	else if (has_duplicated_numbers(count, args))
	{
		ft_printf("duplicated number\n");
		exit(EXIT_FAILURE);
	}
	else if (if_numbers_are_sorted(count, args))
		ft_printf("numeros ordenados\n");
	else
		ft_printf("valid input\n");
	free(args);
}
