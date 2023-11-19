/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/19 03:20:46 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate_number(char **argv)
{


	/*
	int	i;
	int	j;

	i = 0;
	j = 1;

	while (argv[1][i] != '\0')
	{
		if (!(argv[1][i] == argv[1][j]))
			return(0);
		i++;
		j++;
	}
	*/
	return (1);
}

int	check_range_number(char *argv[])
{
	int	i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' && argv[1][i] > '9') 
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
 * example input:
 * CASE 1:
 * ./push_swap 1 3 5 6 7
 *
 * CASE 2:
 * ARG="4 1 9 2"./push_swap $ARG | wc -l
 *
 */

void	check_all_input(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc < 2)
		write (1, "error\n",6);
	else
	{
		//funcion comprobar que no se repitan los numeros
		//if (check_range_number(argv) || check_duplicate_number(argv))
		if (check_duplicate_number(argv))
			write(1, "valid input\n", 12);
		else
			write(1, "invalid input\n", 14);
	}
}

int	main(int argc, char *argv[])
{
	check_all_input(argc, argv);
	return (0);
}
