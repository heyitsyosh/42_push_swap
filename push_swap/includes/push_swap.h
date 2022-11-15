/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:12:15 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/15 20:38:22 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
# include "./get_next_line.h"
# include "./ft_printf.h"

# define NO_COMMAND 0
# define PA 1
# define PB 2
# define SA 3
# define SB 4
# define SS 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_stack
{
	struct s_stack	*prev;
	int				input;
	int				cc;
	int				i_s_len;
	bool			part_of_lis;
	struct s_stack	*next;
}	t_stack;

typedef struct s_command
{
	int					command;
	struct s_command	*next;
}	t_command;

typedef struct s_save
{
	int			argc;
	t_stack		*a_head;
	t_stack		*b_head;
	t_stack		*a_tail;
	t_stack		*b_tail;
	int			a_size;
	int			b_size;
	int			first_pivot;
	int			second_pivot;
	t_stack		*lis;
	t_stack		*lis_end;
	t_command	*commands;
	t_command	*last_command;
	bool		sorted;
	bool		has_duplicate;
}	t_save;

//-----------------------------------------------------------------------//

void tmp_print(t_save *s, char *command);
void	tmp_print_bool(t_save *s);
void	tmp_print_lis(t_save *s);

bool	make_stack_a_and_b(t_save *s, int argc, char **argv);
int		atoi_with_overflow_check(const char *str, bool *overflow);
void	get_lis_and_compressed_coordinates(t_save *s);

t_stack	*stack_min(t_stack *head);
void	stack_add_back(t_stack *node, t_stack **tail);
void	stack_add_front(t_stack *node, t_stack **head, t_stack **tail);
void	free_nodes(t_save *s);

void	sort_few(int stack_size, t_save *s);
void	sort_many(t_save *s);

void	combine(t_save *s);
void	find_combo(t_save *s);
int		find_distance_to_cc(int cc, t_stack *next);
bool	ss_if_optimal(t_save *s);
bool	rr_if_optimal(int original_command, int x, t_save *s);

void	append_command(t_save *s, int command);
bool	reduce_commands(t_save *s);
void	print_commands(t_save *s);

//-----------------------------------------------------------------------//

void	pa(t_save *s, int command);
void	pb(t_save *s, int command);

void	sa(t_save *s, int command);
void	sb(t_save *s, int command);
void	ss(t_save *s, int command);

void	ra(t_save *s, int command);
void	rb(t_save *s, int command);
void	rr(t_save *s, int command);

void	rra(t_save *s, int command);
void	rrb(t_save *s, int command);
void	rrr(t_save *s, int command);

#endif