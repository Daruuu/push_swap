/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:05:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/16 16:28:25 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL; 
    stack_b = NULL; 
    if (ac < 2)
        return(0);
    input_check_argc(ac, av);

    stack_a = init_stack(ac, av);
    stack_b = init_stack_empty();

    ft_printf("initial stack lenght: %d\n", stack_a->len);

    handle_sort_options(&stack_a, &stack_b, stack_a->len);
    ft_printf("stack A:\n");
    print_stack(stack_a);
    //free(stack_a);
    return (0);
}

/*
#include "../push_swap.h"
#include "./Unity/src/unity.h"

void setUp(void) {}
void tearDown(void) {}

void test_sort_stack_three_numbers_case_213(void) {
    t_stack *stack = init_stack(3, (char*[]){ "2", "1", "3"});
    sort_stack_three_numbers(&stack);
    TEST_ASSERT_EQUAL_INT(1, stack->head->data);
    TEST_ASSERT_EQUAL_INT(2, stack->head->next->data);
    TEST_ASSERT_EQUAL_INT(3, stack->head->next->next->data);
    free_stack(stack);
}

void test_sort_stack_three_numbers_case_321(void) {
    t_stack *stack = init_stack(3, (char*[]){ "3", "2", "1" });
    sort_stack_three_numbers(&stack);
    TEST_ASSERT_EQUAL_INT(1, stack->head->data);
    TEST_ASSERT_EQUAL_INT(2, stack->head->next->data);
    TEST_ASSERT_EQUAL_INT(3, stack->head->next->next->data);
    free_stack(stack);
}

//  Añadir más casos de prueba aquí

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sort_stack_three_numbers_case_213);
    RUN_TEST(test_sort_stack_three_numbers_case_321);
    // Añadir más casos de prueba aquí
    return UNITY_END();
}
*/
