/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:11:48 by dasalaza          #+#    #+#             */
/*   Updated: 2024/04/23 10:57:01 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/*
void    del(void *content)
{
    free(content);
}

int main()
{
    t_list  *lista = NULL;
    t_list  *node01 = (t_list *) malloc(sizeof(t_list));
    t_list  *node02 = (t_list *) malloc(sizeof(t_list));
    t_list  *node03 = (t_list *) malloc(sizeof(t_list));
    t_list  *node04 = (t_list *) malloc(sizeof(t_list));
    t_list  *node05 = (t_list *) malloc(sizeof(t_list));

    node01->content = "node01";
    node01->next = NULL;
    node02->content = "node02";
    node02->next = NULL;
    node03->content = "node03";
    node03->next = NULL;
    node04->content = "node04";
    node04->next = NULL;
    node05->content = "nuevo contenido";
    node05->next = NULL;

    lista = node01;
    node01->next = node02;
    node02->next = node03;
    node03->next = node04;
    node04->next = node05;

    int sizeList = ft_lstsize(lista);
    printf("size of list before execute function: %d \n", sizeList);

    ft_lstdelone(node05, del);

    printf("iterate through list again:\n");

    t_list  *current = lista;
    node04->next = NULL;

    sizeList = 0;
    while (current != NULL)
    {
        printf("%s\n", (char *) current->content);
        current = current->next;
        sizeList++;
    }
    printf("size of list after execute function: %d \n", sizeList);
	free(lista);

    return (0);
}
*/
