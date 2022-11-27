/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:09:09 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/28 05:59:51 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//finds the closest sortable node
bool	find_sortable(t_stack *next, t_stack *prev, t_combine *c, t_info *i)
{
	int		bottom;

	c->distance_from_head = 0;
	c->distance_from_tail = 1;
	if (i->a_tail->cc + 1 == i->a_size + i->b_size)
		bottom = 0;
	else
		bottom = i->a_tail->cc + 1;
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

static void	move_to_sortable(t_combine *c, t_info *i)
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

static void	sort_into_a(t_combine *c, t_info *i)
{
	while (1)
	{
		if (!find_sortable(i->b_head, i->b_tail, c, i))
			return ;
		move_to_sortable(c, i);
		pa(i, PA);
		if (i->a_head->cc != c->median)
			ra(i, RA);
		else
			c->median++;
	}
}

void	combine(t_info *i)
{
	t_combine	c;
	int			biggest_cycle;

	first_adjust(&c, i);
	biggest_cycle = mark_cycles(i);
	c.cycle = 0;
	while (i->b_size > 0)
	{
		if (c.cycle % 2 == 0)
			adjust_a(&c, i);
		else
		{
			get_median_of_to_push(i->b_head, &c);
			sort_into_a(&c, i);
		}
		c.cycle++;
	}
}
