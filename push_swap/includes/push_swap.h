/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:12:15 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 18:04:10 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
# include "./get_next_line.h"
# include "./ft_printf.h"

# define NO_PRINTF 0
# define PRINTF 1

typedef struct s_stack
{
	struct s_stack	*prev;
	int				input;
	int				cc;
	int				lmis;
	struct s_stack	*next;
}	t_stack;

typedef struct s_save
{
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack	*lmis_i;
	t_stack	*lmis_ii;
	t_stack	*lmis_iii;
	int		min;
	bool	has_duplicates;
}	t_save;

bool	make_stack_a_and_b(t_save *s, int argc, char **argv);
int		atoi_with_overflow_check(const char *str, bool *overflow);
void	get_lmis_and_compressed_coordinates(t_save *s);

t_stack	*stack_last(t_stack *head);
void	stack_add_back(t_stack *node, t_stack *head);
void	free_a_and_b(t_save *s);

#endif