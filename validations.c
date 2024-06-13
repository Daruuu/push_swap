/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:02:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/13 11:23:14 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	has_invalid_charecters(int count, char **av)
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
	while (i < ac -1)
	{
		if (ft_atoi(av[i]) > ft_atoi(av[i + 1]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	check_all_input(int argc, char **argv)
{
	char	**args;
	int		count;

	args = split_arguments(argc, argv, &count);
	if (count < 1)
	{
		ft_printf("error argc test\n");
		return ;
	}
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
