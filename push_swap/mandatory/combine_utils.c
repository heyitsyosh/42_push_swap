/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:51:21 by myoshika          #+#    #+#             */
/*   Updated: 2022/12/03 19:16:03 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_appropriate_a_head(t_stack *target, t_info *i)
{
	t_stack	*next;
	t_stack	*a_min;

	a_min = stack_min(i->a_head);
	if (target->cc > (stack_max(i->a_head))->cc)
		return (a_min);
	next = a_min;
	while (next)
	{
		if (target->cc < next->cc)
			return (next);
		next = next->next;
	}
	next = i->a_head;
	while (next)
	{
		if (target->cc < next->cc)
			return (next);
		next = next->next;
	}
	return (next);
}

void	update_optimal_actions(bool	not_first_call, t_stack *t, t_combine *c)
{
	int	optimal_cost;

	optimal_cost = 0;
	if (not_first_call)
	{
		optimal_cost = c->optimal_ra + c->optimal_rra;
		optimal_cost += c->optimal_rb + c->optimal_rrb;
	}
	if (!not_first_call
		|| (t->ra_cost + t->rra_cost + t->rb_cost + t->rrb_cost <= optimal_cost
			&& t->ra_cost + t->rra_cost + t->rb_cost + t->rrb_cost >= 0))
	{
		c->optimal_ra = t->ra_cost;
		c->optimal_rra = t->rra_cost;
		c->optimal_rb = t->rb_cost;
		c->optimal_rrb = t->rrb_cost;
	}
}

static void	set_stack_a_actions(int ra, int rra, t_stack *target)
{
	target->ra_cost = ra;
	target->rra_cost = rra;
}

static void	set_stack_b_actions(int rb, int rrb, t_stack *target)
{
	target->rb_cost = rb;
	target->rrb_cost = rrb;
}

void	pick_optimal(t_stack *t, t_costs *c)
{
	if (c->ra_rrb < c->rra_rb && c->ra_rrb < c->ra_rb && c->ra_rrb < c->rra_rrb)
	{
		set_stack_a_actions(t->ra_cost, 0, t);
		set_stack_b_actions(0, t->rrb_cost, t);
	}
	else if (c->rra_rb < c->ra_rrb && c->rra_rb < c->ra_rb
		&& c->rra_rb < c->rra_rrb)
	{
		set_stack_a_actions(0, t->rra_cost, t);
		set_stack_b_actions(t->rb_cost, 0, t);
	}
	else if (c->ra_rb < c->ra_rrb && c->ra_rb < c->rra_rb
		&& c->ra_rb < c->rra_rrb)
	{
		set_stack_a_actions(0, t->rra_cost, t);
		set_stack_b_actions(t->rb_cost, 0, t);
	}
	else if (c->rra_rrb < c->ra_rrb && c->rra_rrb < c->rra_rb
		&& c->rra_rrb < c->ra_rb)
	{
		set_stack_a_actions(0, t->rra_cost, t);
		set_stack_b_actions(t->rb_cost, 0, t);
	}
}

