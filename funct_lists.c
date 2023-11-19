/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:08:49 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/19 20:28:10 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct lib_list
{
	void			*content;
	struct lib_list	*next;
}					l_list;

l_list	*ft_lstnew(void *content)
{
	l_list	*new_list;
	
	//new_list = (l_list *) malloc(sizeof(*new_list));
	if (!(new_list = (l_list *) malloc( sizeof(*new_list) )))
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new -> next = *lst;
		*lst = new;
	}
}
