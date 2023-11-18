/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:01:12 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/18 23:56:35 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate_number(char *argv)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == argv[j])
			return(1);
		i++;
		j++;
	}
	return (0);
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

void	check_type_input(int args, char *argv[])
{
	int	i;

	i = 0;
	if (args != 2)
	{
		write (1, "error\n",6);
	}
	else
	{
		while (argv[i][0] != '\0')
		{
			//funcion comprobar que no se repitan los numeros

			i++;
		}

	}
}


int	main(int args, char *argv[])
{

}
