/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:58:23 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/22 14:39:00 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# define MAX_CASE 500

# include "lib/libft/libft.h"
# include "lib/libft/printf/ft_printf.h"

# include <unistd.h>
# include <limits.h>

/*
 * @attribute data: data of node
 * @attribute index : index nodo
 * @attribute previous : pointer of before node
 * @attribute next : pointer to next node
*/

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*previous;
	struct s_node	*next;
}		t_node;

typedef struct s_stack
{
	int		len;
	t_node	*head;
	t_node	*tail;
}		t_stack;

/*	INPUT_VALIDATIONS.C	*/
int		is_valid_number(char *str);
int		has_invalid_characters(int count, char **av);
int		has_duplicated_numbers(int ac, char **av);
int		if_numbers_are_sorted(int ac, char **av);

/*	INPUT_CHECK.C	*/
void	check_all_validations(int ac, char **av);
void	input_check_argc(int ac, char **av);

/*	STACK_UTILS.C	*/
t_stack	*init_stack(int ac, char **av);
t_stack	*init_stack_empty(void);
void	print_stack(t_stack *stack);
int		ft_size_stack(t_stack *stack);
//int		stack_is_sorted(t_stack *stack_a);

/*	STACK_HELPER.C	*/
//t_node	*get_before_last_node_stack(t_stack *stack);
int		min_index_stack(t_stack *stack);
int		max_index_stack(t_stack *stack);
t_node	*get_tail_of_stack(t_stack *stack);
t_node	*create_new_node(char **av, int i);
t_stack	*set_stack_null(t_stack *stack);

//t_stack	*stack_with_split(char **av);

/*	SWAPS_OPERATIONS.C	*/
void	swap_nodes(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/*	ROTATES_OPERATIONS.C	*/
void	rotate_stack(t_stack *stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

/*	REV_ROTATES_OPERATIONS.C	*/
void	reverse_rotate_stack(t_stack *stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/*	PUSH_OPERATIONS.C	*/
void	push_move(t_stack **stack_src, t_stack **stack_dest);
void	push_a(t_stack **stack_src, t_stack **stack_dest);
void	push_b(t_stack **stack_src, t_stack **stack_dest);

/*	FREE_AND_ERRORS.C	*/
void	free_allocs(int ac, t_stack *sa, t_stack *sb, char **new_argv);
void	free_node(t_node *node);
void	free_split(char **split);
void	free_stack(t_stack *stack);
int		is_stack_null(t_stack *stack);

/*	DIFF_SORT_OPTIONS.C	*/
void	sort_stack_three_numbers(t_stack *stack);
void	sort_stack_four_numbers(t_stack *stack_a, t_stack *stack_b);
void	sort_stack_five_numbers(t_stack *stack_a, t_stack *stack_b);
t_stack	*handle_sort_options(t_stack **sa, t_stack **sb, int len_stack);

/*	STACK_AUX.C???	*/
int		ft_atoi(const char *str);
t_node	*find_min_node(t_stack *stack, int threshold);
void	set_index_stack(t_stack *stack);
int		stack_is_sorted_by_index(t_stack *stack_a);

void	float_min_number_four_stack(t_stack *stack_a);
void	float_min_number_five_stack(t_stack *stack_a);

/*	CHUNK_ALGORITHM.C	*/
void	move_nodes_from_a_to_b(t_stack *stk_a, t_stack *stk_b, int chunk_size);
void	move_nodes_from_b_to_a(t_stack *stk_a, t_stack *stk_b);

#endif
