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
