/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_use.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:56:14 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/08 19:36:34 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	number_out_of_range(long long *result)
{
	if (*result > INT_MAX || *result < INT_MIN)
	{
		ft_printf("number out of range");
		exit(EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				signo;
	long long		result;

	i = 0;
	signo = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	result *= signo;
	number_out_of_range(&result);
	return ((int)result);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_lst_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
