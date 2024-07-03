/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 19:53:30 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/03 17:17:04 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// TODO: change name of file!
/*
 * this is function execute after fill the list with the argv
*/

/*
void	print_stack(int argc, char **argv)
{
	t_stack	stack_a;

	stack_a = fill_linked_list (argc, argv);
	t_node	*current = stack_a.first;

	while (current != NULL)
	{
		current->index, current->value
		current = current->next;
		printf("index: [%d] -> value: %d\n", current->index, current->value);
	}
}
*/
/*
void	print_stack(int argc, char **argv)
{
	t_stack	**stack_a;
	t_node	*current;

	current = NULL;
	stack_a = fill_linked_list(argc, argv);
	current = stack_a.first;
	while (current != NULL)
	{
		printf("index: [%d] -> value: %d\n", current->index, current->value);
		current = current->next;
	}
}
*/

/*
 * fill STACK A with argv[1]
*/
/*
t_stack	*fill_stack_a(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		value;
	t_node	*new_node;

	stack_a->len = 0;
	stack_a->head = NULL;
	i = 1;
	while (i < argc - 1)
		i++;
	ft_printf("%d\n", i);
	i = 0;
	while (i < argc - 1)
	{
		value = ft_atoi(argv[i]);
		new_node = malloc (sizeof(t_node *));
		if (!new_node)
		{
			ft_printf("error fill linked list\n");
			free(new_node);
		}
		stack_a->value = value;
		new_node->index = i - 1;	//?????????
		new_node->next = stack_a.first;
		new_node->previous = NULL;
		if (stack_a.first != NULL)
			stack_a.first->previous = new_node;
		stack_a->head = new_node;
		stack_a->len++;
		i++;
	}
	set_index_in_stack(&(stack_a.first));
	return (stack_a);
}
*/
#include <stdio.h>

// Función para contar el número de argumentos
int count_arguments(int ac, char **av) {
    int count = 0;
    for (int i = 1; i < ac; i++) {
        count++;
    }
    return (count);
}

int	main(int ac, char **av) {

    int     i;
    int     value;
    /*
    t_stack *stack_a;
    t_node  *new_node;
    stack_a = (t_stack *)malloc(sizeof(t_stack));
    stack_a->len = 0;
    stack_a->head = NULL;
    */

    // Usar la función count_arguments para obtener la cantidad de argumentos
    int arg_count = count_arguments(ac, av);
    printf("Number of arguments: %d\n", arg_count);
    i = 1;
    while (i < av - 1)
    {
        printf("argument: [%d] => %d\n", i, av);
        i++;
    }
    
    free(stack_a);
    return 0;
}

