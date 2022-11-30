/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:45:48 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/30 13:52:24 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_appropriate_a_head(t_info *i)
{
	t_stack	*next;
	t_stack	*to_pa;
	t_stack	*a_min;

	to_pa = i->b_head;
	a_min = stack_min(i->a_head);
	if (to_pa->cc > (stack_max(i->a_head))->cc)
		return (a_min);
	next = a_min;
	while (next)
	{
		if (to_pa->cc < next->cc)
			return (next);
		next = next->next;
	}
	next = i->a_head;
	while (next)
	{
		if (to_pa->cc < next->cc)
			return (next);
		next = next->next;
	}
	return (next);
}

static void	calc_cost(int *ra_cost, int *rra_cost, t_combine *c, t_info *i)
{
	if (c->distance_from_tail < c->distance_from_head)
	{
		if (c->distance <= i->a_size / 2)
			*ra_cost = c->distance;
		else
			*rra_cost = (i->a_size - c->distance) - c->distance_from_tail;
	}
	else
	{
		if (c->distance <= i->a_size / 2)
			*ra_cost = c->distance - c->distance_from_head;
		else
			*rra_cost = (i->a_size - c->distance);
	}
	if (*ra_cost < 0)
		*ra_cost *= -1;
	if (*rra_cost < 0)
		*rra_cost *= -1;
}

void	adjust_a(t_combine *c, t_info *i)
{
	t_stack	*new_a_head;
	int		ra_cost;
	int		rra_cost;

	new_a_head = find_appropriate_a_head(i);
	c->distance = find_distance_to_cc(new_a_head->cc, i->a_head);
	calc_cost(&ra_cost, &rra_cost, c, i);
	if (rra_cost < ra_cost)
		while (i->a_head != new_a_head)
			rra(i, RRA);
	else
		while (i->a_head != new_a_head)
			ra(i, RA);
}
