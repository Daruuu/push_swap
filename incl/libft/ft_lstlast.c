/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:35:49 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/23 10:35:33 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

/*
int main()
{
    t_list  *lista_test = NULL;

    t_list  *node01 = (t_list *) malloc (sizeof(t_list));
    t_list  *node02 = (t_list *) malloc (sizeof(t_list));
    t_list  *node03 = (t_list *) malloc (sizeof(t_list));
    t_list  *node04 = (t_list *) malloc (sizeof(t_list));

    //add data to nodes

    node01->content = "abcd";
    node01->next = NULL;
    node02->content = "efgh";
    node02->next = NULL;
    node03->content = "ijkl";
    node03->next = NULL;
    node04->content = "lmno";
    node04->next = NULL;

    // construir la lista
    lista_test = node01;
    node01->next = node02;
    node02->next = node03;
    node03->next = node04;

    t_list  *last_node;
    last_node = ft_lstlast(lista_test);
    printf("last node: %s\n", last_node->content);

    //free(lista_test);

    free(node01);
    free(node02);
    free(node03);
    free(node04);

    return (0);
}
*/
