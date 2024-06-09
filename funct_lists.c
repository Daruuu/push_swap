/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:08:49 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/05 10:38:55 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_lista
{
	void			*content;
	struct s_lista	*next;
}		t_lista;

t_lista	*ft_lstnew(void *content)
{
	t_lista	*new_list;

	new_list = NULL;
	if (!(new_list == (t_lista *) malloc(sizeof(*new_list))))
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_front(t_lista **lst, t_lista *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

/*
int	ft_lst_size(t_list *lst)
{
	size_t	i;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
*/
