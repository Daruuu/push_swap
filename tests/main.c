/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:05:13 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/21 16:42:14 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
	char	**new_arg;
	int 	len_new_ac;

    stack_a = NULL; 
    stack_b = NULL;
    if (ac < 2)
        return(0);
	else if (ac == 2)
	{
		new_arg = ft_split(av[1], ' ');
		len_new_ac = 0;
		while(new_arg[len_new_ac])
			len_new_ac ++;
		ac = len_new_ac;
	}
	input_check_argc(ac, av);
	stack_a = init_stack(ac, av);
    stack_b = init_stack_empty();
	set_index_stack(stack_a);
    handle_sort_options(&stack_a, &stack_b, stack_a->len);
//	print_stack(stack_a);
	free_allocs(ac, stack_a, stack_b, new_arg);
	return (0);
}

/*
int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
	char	**new_arg;
	int 	len_new_ac;

    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2)
        return(0);
	else if (ac == 2)
	{
		new_arg = ft_split(av[1], ' ');
		len_new_ac = 0;
		while(new_arg[len_new_ac])
			len_new_ac ++;

//		ft_printf("len_new AC: %d\n", len_new_ac);

		input_check_argc(len_new_ac, new_arg - 1);
		stack_a = init_stack(len_new_ac, new_arg - 1);
	}
	else if (ac > 2)
	{
		input_check_argc(ac, av);
		stack_a = init_stack(ac, av);
	}
    stack_b = init_stack_empty();
//    ft_printf("initial stack lenght: %d\n", stack_a->len);
//	ft_printf("initial stack lenght: %d\n", stack_b->len);
	set_index_stack(stack_a);
//	ft_printf("INDEX:\n");
//    print_stack(stack_a);
    handle_sort_options(&stack_a, &stack_b, stack_a->len);
//	ft_printf("STACK A ORDENADO:\n");
//	print_stack(stack_a);
	free_stack(stack_b);
	free_stack(stack_a);
	if (ac == 2)
		free_split(new_arg);
	return (0);
}
 */

/*
	ft_printf("stack A:\n");
	print_stack(stack_a);
*/
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
