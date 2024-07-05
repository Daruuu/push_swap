/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:02:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/04 21:09:25 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//$> ARG="1 3 6 12 6"; ./push_swap $ARG | wc -lo
// $> ./push_swap 1 23 45 -11 -1 | wc -lo

int	is_valid_number(int str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

//static int	has_invalid_characters(int count, char **av)
int	has_invalid_characters(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			return (1);
		i++;
	}
	return (FALSE);
}

// static int	has_duplicated_numbers(int ac, char **av)
int	has_duplicated_numbers(int ac, char **av)
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

// static int	if_numbers_are_sorted(int ac, char **av)
int	if_numbers_are_sorted(int ac, char **av)
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

/*
void	check_all_inputs(int ac, char **av)
{
	char	**args;
	int		count;

	if (ac < 2)
	{
		ft_printf("error argc\n");
		exit (EXIT_FAILURE);
	}
	ft_printf("check_all_input(): %d\n", ac);

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
*/