/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:12:15 by myoshika          #+#    #+#             */
/*   Updated: 2022/12/04 05:04:30 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int				input;
	int				cc;
	int				cycle;
	int				i_s_len;
	int				no_lis_cc;
	bool			part_of_lis;
	bool			to_push;
	int				rb_cost;
	int				rrb_cost;
	int				ra_cost;
	int				rra_cost;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_command
{
	int					command;
	struct s_command	*next;
}	t_command;

typedef struct s_info
{
	int			argc;
	t_stack		*a_head;
	t_stack		*b_head;
	t_stack		*a_tail;
	t_stack		*b_tail;
	int			a_size;
	int			b_size;
	t_stack		*lis;
	t_command	*commands;
	t_command	*last_command;
	int			b_pivot;
	bool		first_divide;
	bool		sorted;
	bool		has_duplicate;
	int			biggest_cycle;
}	t_info;

typedef struct s_combine
{
	t_stack	*optimal_a_head;
	int		optimal_ra;
	int		optimal_rra;
	int		optimal_rb;
	int		optimal_rrb;
	int		cycle;
	int		distance;
}	t_combine;

typedef struct s_costs
{
	int		ra_rrb;
	int		rra_rb;
	int		ra_rb;
	int		rra_rrb;
}	t_costs;

//-----------------------------------------------------------------------//

void	make_stack_a_and_b(t_info *i, int argc, char **argv);
int		atoi_with_overflow_check(const char *str, bool *overflow);
void	get_lis_and_compressed_coordinates(t_info *i);

t_stack	*stack_min(t_stack *head);
t_stack	*stack_max(t_stack *head);
void	stack_add_back(t_stack *node, t_stack **tail);
void	stack_add_front(t_stack *node, t_stack **head, t_stack **tail);
void	free_nodes(t_info *i);

void	sort_few(int stack_size, t_info *i);

void	sort_many(t_info *i);
void	divide(int pivot, int total_pushed, int cycle, t_info *i);
void	combine(t_info *i);

int		get_median(t_stack *head);
int		get_first_quartile(t_stack *head);
int		distance_from_top(int cc, t_stack *next);
int		distance_from_bottom(int cc, t_stack *prev);
t_stack	*find_appropriate_a_head(t_stack *target, t_info *i);
void	pick_optimal(t_stack *t, t_costs *c);
void	update_optimal_actions(bool	not_first_call, t_stack *t, t_combine *c);

void	append_command(t_info *i, int command);
bool	reduce_commands(t_info *i);
void	print_commands(t_info *i);

//-----------------------------------------------------------------------//

void	pa(t_info *i, int command);
void	pb(t_info *i, int command);

void	sa(t_info *i, int command);
void	sb(t_info *i, int command);
void	ss(t_info *i, int command);

void	ra(t_info *i, int command);
void	rb(t_info *i, int command);
void	rr(t_info *i, int command);

void	rra(t_info *i, int command);
void	rrb(t_info *i, int command);
void	rrr(t_info *i, int command);

#endif