/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:58:23 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/25 13:50:57 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
//# include "srcs/src_libft/libft.h"

typedef struct s_node
{
	int value;
	int index;
	struct s_node *next;
}	t_node;

typedef struct s_stack
{
	int len;
	struct s_node *first;
}		t_stack;	

void	check_all_input(int argc, char **argv);
t_stack	fill_linked_list(int argc, char **argv);
void	print_stack(int argc, char **argv);
int		ft_lst_size(t_list *lst);
int		ft_atoi(const char *str);



#endif
