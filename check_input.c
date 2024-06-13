/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/13 14:07:29 by dasalaza         ###   ########.fr       */
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

char	**split_arguments(int ac, char **av, int count_args)
{
	char	**split;
	char	**result;
	int		i;
	int		j;

	if (ac == 2)
		split = ft_split(av[1], ' ');
	else
		return (av + 1);
	i = 0;
	while (split[i])
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[i] = split[j];
		j++;
	}
	result[j] = NULL;
	count_args = i;
	free(split);
	return (result);
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

/*
static int	if_numbers_are_sorted(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (ft_atoi(&av[1][i]) > ft_atoi(&av[1][i + 1]))
				return (FALSE);
			i++;
		}
	}
	return (TRUE);
}
*/

/*
void	check_all_input(int argc, char **argv)
{
	if (argc != 2)
		ft_printf("error argc test\n");
	else
	{
		if (has_invalid_characters(argv))
		{
			ft_printf("invalid character\n");
			exit(EXIT_FAILURE);
		}
		else if (has_duplicated_numbers(argc, argv))
		{
			ft_printf("duplicated number\n");
			exit(EXIT_FAILURE);
		}
		else if (has_duplicated_negative_sign(argv))
		{
			ft_printf("double negative sign\n");
			exit(EXIT_FAILURE);
		}
		else if (if_numbers_are_sorted(argv))
			ft_printf("numeros ordenados\n");
		else
			ft_printf("valid input\n");
	}
}
*/
