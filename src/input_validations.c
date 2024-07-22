/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:02:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/22 12:17:41 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
$> ARG="1 3 6 12 6"; ./push_swap $ARG | wc -lo
$> ./push_swap 1 23 45 -11 -1 | wc -lo
*/

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!(ft_isdigit(str[i])))
		return (FALSE);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

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
