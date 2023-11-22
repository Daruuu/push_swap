/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:58:23 by dasalaza          #+#    #+#             */
/*   Updated: 2023/11/22 16:05:24 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "srcs/src_libft/libft.h"

typedef struct s_list
{
	int value;
	int index;
	struct s_list *next;
}	t_list;

typedef struct s_stack
{
	int len;
	struct s_list *first;
}		t_stack;	

void	check_all_input(int argc, char **argv);
t_stack	fill_t_list(int argc, char **argv);
void	print_stack(int argc, char **argv);

#endif
