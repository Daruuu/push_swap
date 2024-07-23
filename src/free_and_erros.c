/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_erros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:30:52 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/23 23:00:26 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_allocs(int ac, t_stack *sa, t_stack *sb, char **new_argv)
{
	free_stack(sb);
	free_stack(sa);
	if (ac == 2)
		free_split(new_argv);
}

void	free_node(t_node *node)
{
	if (node)
		free(node);
	node = NULL;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int	is_stack_null(t_stack *stack)
{
	if (!stack)
		return (1);
	return (0);
}
