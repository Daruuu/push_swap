/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:30:19 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/19 02:33:53 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
void	free_lista(t_list *head)
{
	t_list	*current;
	t_list	*temp;

	current = head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

int	main()
{
	t_list	*lista = NULL;

	t_list	*node1 = (t_list *) malloc(sizeof(t_list));
	t_list	*node2 = (t_list *) malloc(sizeof(t_list));
	t_list	*node3 = (t_list *) malloc(sizeof(t_list));
    t_list	*node4 = (t_list *) malloc(sizeof(t_list));

	node1->content = "First";
	node1->next = NULL;
	node2->content = "second";
	node2->next = NULL;
	node3->content = "third";
	node3->next = NULL;
    node4->content = "fourth";
    node4->next = NULL;
	
	lista = node1;
	//lista->next = node1;	// error comun
	node1->next = node2;
	node2->next = node3;
    node3->next = node4;

	// testing here
	int	size = ft_lstsize(lista);
	printf("length of lista is: %d\n", size);

	// new node
	t_list	*new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
	{
		free_lista(lista);
		return(0);
	}
	new_node->content = "new node";
	new_node->next = NULL;
	node4->next = new_node;

	t_list	*current = lista;

	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	size = ft_lstsize(lista);
	printf("length of list after call functino is: %d\n", size);
	free_lista(lista);

	return (0);
}
*/
