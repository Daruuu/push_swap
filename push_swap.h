/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:58:23 by dasalaza          #+#    #+#             */
/*   Updated: 2024/06/17 22:57:58 by dasalaza         ###   ########.fr       */
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

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*previous;
	struct s_node	*next;
}			t_node;

typedef struct s_stack
{
	int				len;
	struct s_node	*head;
}		t_stack;

/*VALIDATIONS.C*/
void	check_all_inputs(int ac, char **av);

/*CHECK_INPUT.C*/
char	**split_arguments(int ac, char **av, int *count_args);
int		has_duplicated_negative_sign(char **av);

/*AUX LIST.C*/
int		ft_size_stack(t_stack *stack);
void	set_index_stack(t_node **head_ref);
int		stack_is_sorted(struct s_stack *stack_a);

t_stack	fill_linked_list(int argc, char **argv);
void	print_stack(int argc, char **argv);

int		ft_lst_size(t_node *lst);
int		ft_atoi(const char *str);
void	set_index_in_stack(t_node **head_ref);

#endif
