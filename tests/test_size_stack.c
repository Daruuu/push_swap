/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_size_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:01:33 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/20 01:08:06 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Crear e inicializar el stack
    t_stack	stack;
    t_node node1 = {10, 0, NULL, NULL};
    t_node node2 = {20, 0, &node1, NULL};
    node1.next = &node2;
    stack.head = &node1;
    stack.len = 0;

    // Calcular el tamaño de la pila
    int size = ft_size_stack(&stack);
    printf("Size of stack: %d\n", size);

    return 0;
}
