/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 23:04:53 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/23 09:42:24 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}
*/
/*
void	free_list(t_list *head)
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
	t_list	*test_lista = NULL;

	test_lista = (t_list *) malloc (sizeof(t_list));
	if (!test_lista)
	{
		free(test_lista);
		return (0);
	}

	// crear nodos
	t_list	*node01 = (t_list *) malloc (sizeof(t_list));
	t_list	*node02 = (t_list *) malloc (sizeof(t_list));
	t_list	*node03 = (t_list *) malloc (sizeof(t_list));
	t_list	*node04 = (t_list *) malloc (sizeof(t_list));

	//asginar contenido a cada nodo
	
	node01->content = "hello";
	node01->next = NULL;
	node02->content = "world";
	node02->next = NULL;
	node03->content = "this is";
	node03->next = NULL;
	node04->content = "a testing";
	node04->next = NULL;

	// CONSTRUIR LA LISTA
	test_lista->next = node01;
	node01->next = node02;
	node02->next = node03;
	node03->next = node04;

	printf("show test_lista before call ft_lstadd_front:\n");

	int	i = 0;
	t_list	*current = test_lista;
	t_list	*temp = NULL;

	printf("\n");
	while (current != NULL)
	{
	printf("Mem: %p node[%d] -> %s\n", current->content, i, 
	(char *) current->content);
		temp = current;
		current = current->next;
		i++;
	}

	// crear nuevo nodo para add front lista

	t_list	*node_to_add_front = (t_list *) malloc (sizeof(t_list));
	if (!node_to_add_front)
	{
		free(node_to_add_front);
		free_list(test_lista);
		return (0);
	}

	node_to_add_front->content = "start here";

	ft_lstadd_front(&test_lista, node_to_add_front);

	printf("\nshow test_lista after call ft_lstadd_front: \n");

	current = test_lista;
	i = 0;
	printf("\n");
	while (current != NULL)
	{
	printf("Mem: %p node[%d]-> %s\n", current->content , i,
			(char *) current->content);
		current = current->next;
		i++;
	}
	free_list(test_lista);

	return (0);
}
*/
