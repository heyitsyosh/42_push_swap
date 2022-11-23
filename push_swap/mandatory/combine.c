/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:09:09 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/23 20:15:26 by myoshika         ###   ########.fr       */
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
		if (prev->cc == i->a_head->cc + 1 || prev->cc + 1 == i->a_tail->cc)
			break ;
		c->distance_from_head++;
		next = next->next;
	}
	while (prev && prev->cycle == c->cycle)
	{
		if (prev->cc == i->a_head->cc + 1 || prev->cc + 1 == i->a_tail->cc)
			break ;
		c->distance_from_tail++;
		prev = prev->prev;
	}
	if (c->distance_from_head == 0 && c->distance_from_tail == 1)
		return (false);
	return (true);
}

static void	swap_if_optimal(t_info *i)
{
	if (i->a_size < 2 || i->b_size < 2)
		return ;
	if (i->b_head->cc + 1 == (i->b_head->next)->cc)
}

static void	move_to_closest_sortable(t_combine *c, t_info *i)
{
	int	j;

	j = 0;
	if (c->distance_from_tail > c->distance_from_head)
	{
		while (j++ < c->distance_from_tail)
		{
			swap_if_optimal();
			rrb(i, RRB);
		}
	}
	else
	{
		while (j++ < c->distance_from_head)
		{
			swap_if_optimal();
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
		if (c->)
			ra(i, RA);
	}
}

void	combine(t_info *i)
{
	t_combine	c;

	c.cycle = i->b_head->cycle;
	while (c.cycle >= 0)
	{
		get_cycle_info(&c, i);
		adjust_a(&c, i);
		sort_cycle_into_a(&c, i);
		c.cycle--;
	}
}
//if smaller than median of division chunk, sort on top of stack with bigger on top
