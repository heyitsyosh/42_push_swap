/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:12:15 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 23:35:48 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
# include "./get_next_line.h"
# include "./ft_printf.h"

# define PA "pa"
# define PB "pb"
# define SA "sa"
# define SB "sb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

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
	t_stack	*a_tail;
	t_stack	*b_tail;
	t_stack	*lmis_i;
	t_stack	*lmis_ii;
	t_stack	*lmis_iii;
	int		min;
	bool	has_duplicate;
}	t_save;

bool	make_stack_a_and_b(t_save *s, int argc, char **argv);
int		atoi_with_overflow_check(const char *str, bool *overflow);
void	get_lmis_and_compressed_coordinates(t_save *s);

t_stack	*stack_last(t_stack *head);
void	stack_add_back(t_stack *node, t_stack **head, t_stack **tail);
void	stack_add_front(t_stack *node, t_stack **head, t_stack **tail);
void	free_a_and_b(t_save *s);

void	sort(t_save *s);

void	pa(t_save *s);
void	pb(t_save *s);

void	sa(t_save *s, char *to_print);
void	sb(t_save *s, char *to_print);

#endif