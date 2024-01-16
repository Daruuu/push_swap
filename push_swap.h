/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:58:23 by dasalaza          #+#    #+#             */
/*   Updated: 2024/01/16 20:47:33 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# include "incl/libft/libft.h"
# include "incl/printf/ft_printf.h"

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*previous;
}			t_node;

typedef struct s_stack
{
	int				len;
	struct s_node	*first;
}			t_stack;

void	check_all_input(int argc, char **argv);
t_stack	fill_linked_list(int argc, char **argv);
void	print_stack(int argc, char **argv);
int		ft_lst_size(t_node *lst);
int		ft_atoi(const char *str);
void	set_index_in_stack(t_node **head_ref);

#endif
