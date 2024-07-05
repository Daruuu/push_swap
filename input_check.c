/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/05 12:16:13 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_arguments(int ac, char **av, int *count_args)
{
	char	**split;
	char	**result;
	int		i;
	int		j;

	if (ac == 2)
		split = ft_split(av[1], ' ');
	else
	{
		//*count_args = ac - 1;
		*count_args = ac;
		return (av + 1);
	}
	i = 0;
	while (split[i])
		i++;
	result = malloc(sizeof(char *) * (i + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = split[j];
		j++;
	}
	result[j] = '\0';
	*count_args = i;
	free(split);
	return (result);
}

int	has_duplicated_negative_sign(char **av)
{
	int	i;
	int	j;

	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (((av[j][i] == '-') && (av[j][i + 1] == '-')))
				return (TRUE);
			i++;
		}
		j++;
	}
	return (FALSE);
}
