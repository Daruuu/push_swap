/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:26:45 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/11 21:11:49 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

void	quantity_of_args(int ac, char **av)
{
	if (ac == 2)
	{
		//split
	}
	else if (ac > 2)
	{
	}
	else
		ft_printf("args = 1 is invalid\n");
}
