/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:12:15 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/22 23:34:08 by myoshika         ###   ########.fr       */
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
	int		argc;
	t_stack	*a_head;
	t_stack	*b_head;
	t_stack	*a_tail;
	t_stack	*b_tail;
	int		a_size;
	int		b_size;
	//int		sorted_count;
	int		smallest_pivot;
	bool	sorted;
	bool	has_duplicate;
}	t_save;

bool	make_stack_a_and_b(t_save *s, int argc, char **argv);
int		atoi_with_overflow_check(const char *str, bool *overflow);
void	get_lmis_and_compressed_coordinates(t_save *s);

t_stack	*stack_min(t_stack *head);
void	stack_add_back(t_stack *node, t_stack **tail);
void	stack_add_front(t_stack *node, t_stack **head, t_stack **tail);
void	free_a_and_b(t_save *s);

void	sort_few(int stack_size, t_save *s);
void	sort_five_or_four(int cc, t_save *s);
void	sort_three(int first, int second, int third, t_save *s);
int		find_distance_to_cc(int cc, t_save *s);

void	sort_many(t_save *s);

void	pa(t_save *s, char *to_print);
void	pb(t_save *s, char *to_print);

void	sa(t_save *s, char *to_print);
void	sb(t_save *s, char *to_print);
void	ss(t_save *s);

void	ra(t_save *s, char *to_print);
void	rb(t_save *s, char *to_print);
void	rr(t_save *s, char *to_print);

void	rra(t_save *s, char *to_print);
void	rrb(t_save *s, char *to_print);
void	rrr(t_save *s, char *to_print);

#endif