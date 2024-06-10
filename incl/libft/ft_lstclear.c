/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:50:29 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/23 09:45:19 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	del(void *content)
{
	free(content);
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!*lst)
		return ;
	while (*lst)
	{
		current = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = current;
	}
	*lst = NULL;
}
/*
void	free_list(t_list *head)
{
	t_list	*current;
	t_list	*tmp;

	current = head;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

int	main()
{
	t_list	*test_lista = NULL;

	test_lista = (t_list *) malloc (sizeof(t_list));

	// crear nodos
	t_list	*node01 = (t_list *) malloc (sizeof(t_list));
	t_list	*node02 = (t_list *) malloc (sizeof(t_list));
	t_list	*node03 = (t_list *) malloc (sizeof(t_list));
	t_list	*node04 = (t_list *) malloc (sizeof(t_list));
	t_list	*node05 = (t_list *) malloc (sizeof(t_list));

	//asginar contenido a cada nodo

	node01->content = "node01";
	node01->next = NULL;
	node02->content = "node02";
	node02->next = NULL;
	node03->content = "node03";
	node03->next = NULL;
	node04->content = "node04";
	node04->next = NULL;
	node05->content = "node05";
	node05->next = NULL;

	// CONSTRUIR LA LISTA
	test_lista = node01;
	node01->next = node02;
	node02->next = node03;
	node03->next = node04;
	node04->next = node05;

	printf("show test_lista before call ft_lstadd_front:\n");

	int	i = 0;
	t_list	*current = test_lista;
	t_list	*temp = NULL;

	printf("\n");
	while (current != NULL)
	{
		printf("Memory: %p node [%d] -> %s\n", current->content, 
		i, (char *) current->content);
		temp = current;
		current = current->next;
		i++;
	}

	// CALL FUNCTION 
	printf("\nCALL FUNCTION FT_LSTCLEAR\n");
	ft_lstclear(&node04, del);

	printf("\nshow test_lista after call ft_lstclear(): \n");

	//current = NULL;
	current = test_lista;
	i = 0;
	printf("\n");
	while (current != NULL)
	{
		printf("Memory: %p node [%d]-> %s\n", current->content , 
				i, (char *) current->content);
		current = current->next;
		i++;
	}

	free_list(test_lista);
	return (0);
}
*/
