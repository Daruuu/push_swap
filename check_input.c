/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/01/04 18:46:15 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicated_numbers(int argc, char **argv)
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
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

static int	has_invalid_characters(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		if (argv[j][i] == '\0')
			return (FALSE);
		while (argv[j][i])
		{
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9') && argv[j][i] != '-')
				return (TRUE);
			i++;
		}
		j++;
	}
	return (FALSE);
}

static int	has_duplicated_negative_sign(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (((argv[j][i] == '-') && (argv[j][i + 1] == '-')))
				return (TRUE);
			i++;
		}
		j++;
	}
	return (FALSE);
}

void	check_all_input(int argc, char **argv)
{
	if (argc < 2)
		write(1, "error argc\n", 11);
	else
	{
		if (has_invalid_characters(argv))
		{
			write(1, "invalid character\n", 19);
			exit(EXIT_FAILURE);
		}
		else if (has_duplicated_numbers(argc, argv))
		{
			write(1, "duplicated number\n", 17);
			exit(EXIT_FAILURE);
		}
		else if (has_duplicated_negative_sign(argv))
		{
			write(1, "double negative sign\n", 20);
			exit(EXIT_FAILURE);
		}
		else
			write(1, "valid input\n", 12);
	}
}
