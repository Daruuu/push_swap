/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:58:23 by dasalaza          #+#    #+#             */
/*   Updated: 2024/07/02 20:44:55 by dasalaza         ###   ########.fr       */
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
}	t_node;

typedef struct s_stack
{
	int		len;
	t_node	*head;
	t_node	*tail;
}		t_stack;

/*VALIDATIONS.C*/
void	check_all_inputs(int ac, char **av);

/*CHECK_INPUT.C*/
char	**split_arguments(int ac, char **av, int *count_args);
int		has_duplicated_negative_sign(char **av);

/*AUX LIST.C*/
int		ft_size_stack(t_stack *stack);
void	print_stack(t_node *stack);
void	set_index_stack(t_node **head_ref);
int		stack_is_sorted(s_stack *stack_a);
t_node	*get_tail_of_stack(t_stack *stack);

/*AUX LIST 2.C*/
t_node	*get_before_last_node_stack(t_stack *stack);

/* SWAPS.C */
void	swap_nodes(t_stack *stack);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_a_b(t_stack *stack_a, t_stack *stack_b);

/* ROTATES.C */
void	rotate_stack(t_stack *stack);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);

/* REVERSE_ROTATES.C */
void	reverse_rotate_stack(t_stack *stack);
void	r_rotate_a(t_stack **stack_a);
void	r_rotate_b(t_stack **stack_b);
void	rev_rotate_a_b(t_stack **stack_b);

/* MOVES_PUSH.C */
void	push_move(t_stack *stack_src, t_stack *stack_dest);

t_stack	fill_linked_list(int argc, char **argv);
void	print_stack(int argc, char **argv);

int		ft_lst_size(t_node *lst);
int		ft_atoi(const char *str);
void	set_index_in_stack(t_node **head_ref);

#endif
