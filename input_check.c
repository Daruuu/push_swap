/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/06 10:43:23 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int count_argc(int ac) {

    int count;
    int i;

    i = -1;
    count = 1;
    while (++i < ac)
        count++;
    return (i);
}

void	input_check(int ac, char **av)
{
	if (ac < 2)
		ft_printf("ac incorrect!\n");
	else
		av ++;
	if (has_invalid_characters(ac - 1, av))
		ft_printf("Error invalid char\n");
	else if (has_duplicated_numbers(ac - 1, av))
		ft_printf("Error duplicate number\n");
	else if (if_numbers_are_sorted(ac - 1, av))
    {
		ft_printf("numbers sorted\n");
	}
}
/*
        array_input = malloc(sizeof(*array_input) * count_ac + 1);
        if (!array_input)
        {
            free(array_input);
            return (0);
        }
        //  contamos los ac
        //  creamos un *ptr y lo rellenamos con todo el input
        i = 1;
        ft_printf("count_ac(): %d\n", count_ac);
        ft_printf("array here\n");
        while (i < count_ac)
        {
            array_input[i] = ft_atoi(av[i]);
            ft_printf("arr[%d] : %d\n", i, array_input[i]);
            i++;
        }
*/

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
/*
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
*/
