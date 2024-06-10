/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:53:47 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/27 19:48:29 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*element;
	void	*tmp;

	if (!lst)
		return (0);
	new_list = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		element = ft_lstnew(tmp);
		if (!element)
		{
			del(tmp);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, element);
		lst = lst->next;
	}
	return (new_list);
}

/*
void	*f(void *content)
{
	int	*value;	
	int	*result;

    value = (int *)content;
    int *result;
    result = malloc(sizeof(int));
    if (!result)
        return (NULL);
    *result = *value * 2;
    return (result);

}

void    del(void *node)
{
    if (node)
        free(node);
    return ;
}
*/

/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*changed_list;
	t_list	*changed_elem;

	changed_list = NULL;
	while (lst)
	{
		changed_elem = ft_lstnew(f(lst->content));
		if (!changed_elem)
		{
			ft_lstclear(&changed_list, del);
			return (NULL);
		}
		ft_lstadd_back(&changed_list, changed_elem);
		lst = lst->next;
	}
	return (changed_list);
}

*/
