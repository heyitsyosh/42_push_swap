/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:09:09 by myoshika          #+#    #+#             */
/*   Updated: 2022/12/04 04:43:35 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	calculate_costs(t_stack *t, t_info *i)
{
	t_costs	c;
	t_stack	*new_a_head;

	new_a_head = find_appropriate_a_head(t, i);
	t->ra_cost = distance_from_top(new_a_head->cc, i->a_head);
	t->rra_cost = distance_from_bottom(new_a_head->cc, i->a_tail) + 1;
	c.ra_rrb = t->ra_cost + t->rrb_cost;
	c.rra_rb = t->rra_cost + t->rb_cost;
	c.ra_rb = t->ra_cost + t->rb_cost - ft_min(t->ra_cost, t->rb_cost);
	c.rra_rrb = t->rra_cost + t->rrb_cost - ft_min(t->rra_cost, t->rrb_cost);
	pick_optimal(t, &c);
}

static bool	mark_costs(t_combine *c, t_info *i)
{
	t_stack	*next;
	bool	has_cycle;

	next = i->b_head;
	has_cycle = false;
	while (next)
	{
		if (next->cycle == c->cycle)
		{
			next->rb_cost = distance_from_top(next->cc, i->b_head);
			next->rrb_cost = distance_from_bottom(next->cc, i->b_tail) + 1;
			calculate_costs(next, i);
			update_optimal_actions(has_cycle, next, c);
			has_cycle = true;
		}
		next = next->next;
	}
	return (has_cycle);
}

static void	adjust_a_and_b(t_combine *c, t_info *i)
{
	while (c->optimal_ra--)
		ra(i, RA);
	while (c->optimal_rra--)
		rra(i, RRA);
	while (c->optimal_rb--)
		rb(i, RB);
	while (c->optimal_rrb--)
		rrb(i, RRB);
}

void	combine(t_info *i)
{
	t_combine	c;

	c.cycle = i->biggest_cycle;
	while (i->b_size != 0)
	{
		while (i->b_size != 0)
		{
			if (!mark_costs(&c, i))
				break ;
			adjust_a_and_b(&c, i);
			pa(i, PA);
		}
		c.cycle--;
	}
	while (i->a_head->cc != 0)
		ra(i, RA);
}
