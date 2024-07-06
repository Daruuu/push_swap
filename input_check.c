/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/06 21:36:59 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_with_split(char **av);

void	check_all_validations(int ac, char **av)
{
	if (has_invalid_characters(ac, av))
		ft_printf("Error invalid char\n");
	else if (has_duplicated_numbers(ac, av))
		ft_printf("Error duplicate number\n");
	else if (if_numbers_are_sorted(ac, av))
		ft_printf("numbers sorted\n");
}

void	input_check_argc(int ac, char **av)
{
	t_stack	*new_stack;

	if (ac < 2)
		ft_printf("ac incorrect!\n");
	if (ac == 2)
	{
		check_all_validations(ac, av);
		new_stack = stack_with_split(av);	
	}
	if (ac > 2)
	{
		check_all_validations(ac, av);
		stack_with_split(av);
	}
}

t_stack	*stack_with_split(char **av)
{
	int		i;
	t_stack	*new_stack;
	char	**split_av;

	split_av = ft_split(av[1], ' ');
	while (split_av[i] != NULL)
		i++;
	new_stack = init_stack(i, split_av);
}

/*
	else
	{
		new_stack = init_stack(ac, av);
		if (!new_stack)
			ft_printf("error init stack\n");
		print_stack(new_stack->head);
	}
*/

/*
t_stack	*stack_with_split(char **av)
{
	int		i;
	t_stack	*new_stack;
	char	**split_av;

	split_av = ft_split(av[1], ' ');
	i = 0;
	while (split_av[i] != NULL)
		i++;
	if (has_invalid_characters(i, split_av))
	{
		ft_printf("Error invalid char\n");
		free_split(split_av);
		return (NULL);
	}
	else if (has_duplicated_numbers(i, split_av))
	{
		ft_printf("Error duplicate number\n");
		free_split(split_av);
		return (NULL);
	}
	else if (if_numbers_are_sorted(i, split_av))
	{
		ft_printf("numbers sorted\n");
		free_split(split_av);
		return (NULL);
	}
	else
	{
		new_stack = init_stack(i, split_av);
		if (!new_stack)
			ft_printf("error init stack\n");
		print_stack(new_stack->head);
		free_split(split_av); // Libera el arreglo split_av
		return (new_stack);
	}
}
*/

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
/*
char	**split_arguments(int ac, char **av)
{
	char	**split;
	char	**result;
	int		i;
	int		j;

	if (ac == 2)
		split = ft_split(av[1], ' ');
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
	result[j] = 0;
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
*/
