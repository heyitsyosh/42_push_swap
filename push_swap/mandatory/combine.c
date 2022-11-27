/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:09:09 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/27 17:51:37 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	find_closest_sortable(t_combine *c, t_info *i)
{
	t_stack	*next;
	t_stack	*prev;

	next = i->b_head;
	prev = i->b_tail;
	c->distance_from_head = 0;
	c->distance_from_tail = 1;
	while (next && next->cycle == c->cycle)
	{
		if (next->cc == c->median || next->cc == i->a_tail->cc + 1)
			break ;
		c->distance_from_head++;
		next = next->next;
	}
	while (prev && prev->cycle == c->cycle)
	{
		if (prev->cc == c->median || prev->cc == i->a_tail->cc + 1)
			break ;
		c->distance_from_tail++;
		prev = prev->prev;
	}
	if (c->distance_from_head == 0 && c->distance_from_tail == 1)
		return (false);
	return (true);
}

static void	swap_if_optimal(int distance, t_info *i)
{
	if (i->b_size < 2 || distance < 2)
		return ;
	if (i->b_head->cc + 1 == (i->b_head->next)->cc)
		sb(i, SB);
}

static void	move_to_closest_sortable(t_combine *c, t_info *i)
{
	int	j;

	j = 0;
	if (c->distance_from_tail < c->distance_from_head)
	{
		while (j++ < c->distance_from_tail)
		{
			swap_if_optimal(c->distance_from_tail, i);
			rrb(i, RRB);
		}
	}
	else
	{
		while (j++ < c->distance_from_head)
		{
			swap_if_optimal(c->distance_from_head, i);
			rb(i, RB);
		}
	}
}

static void	sort_cycle_into_a(t_combine *c, t_info *i)
{
	while (1)
	{
		if (!find_closest_sortable(c, i))
			return ;
		move_to_closest_sortable(c, i);
		pa(i, PA);
		if (i->a_head->cc == c->median)
		{
			ra(i, RA);
			c->median--;
		}
	}
}

void	combine(t_info *i)
{
	t_combine	c;

	c.cycle = i->b_head->cycle;
	c.a_min = stack_min(i->a_head);
	while (c.cycle >= 0)
	{
		c.b_min = stack_min(i->b_head);
		adjust_a(&c, i);
		set_info(&c, i);
		sort_into_a(&c, i);
		c.cycle--;
	}
}
