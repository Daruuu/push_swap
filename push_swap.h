/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:58:23 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/15 20:45:09 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include "incl/libft/libft.h"
# include "incl/libft/printf/ft_printf.h"

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/*
 * @attribute data: is data of node
 * @attribute index : indice del nodo
 * @attribute previous : puntero al anterior nodo
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

/*	MAIN.C???	*/
void	input_check_argc(int ac, char **av);

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
void	set_index_stack(t_node **head_ref);
int		ft_size_stack(t_stack *stack);
int		stack_is_sorted(t_stack *stack_a);

/*	STACK_HELPER.C	*/
t_node	*get_before_last_node_stack(t_stack *stack);
t_node	*get_tail_of_stack(t_stack *stack);
t_node	*create_new_node(char **av, int i);
t_stack	*set_stack_null(t_stack *stack);
t_stack	*stack_with_split(char **av);
int		find_min_node_position(t_stack *stack);
int		max_num_in_stack(t_stack *stack);

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
void	free_each_node(t_stack **stack);
void	free_node(t_node *node);
void	free_split(char **split);
void	free_stack(t_stack *stack);
int		is_stack_null(t_stack *stack);

/*	DIFF_SORT_OPTIONS.C	*/
void	sort_stack_three_numbers(t_stack *stack);
void	sort_stack_five_numbers(t_stack **stack_a, t_stack **stack_b);
t_stack	*handle_sort_options(t_stack **sa, t_stack **sb, int len_stack);
/*t_stack	*handle_sort_options(t_stack *stack, int len_stack, t_stack *stack_b);*/

/*	NO_USE.C???	*/
int		ft_lst_size(t_node *lst);
int		ft_atoi(const char *str);
void	set_index_in_stack(t_node **head_ref);

#endif
