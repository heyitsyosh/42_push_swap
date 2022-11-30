/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:09:09 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/30 13:52:13 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	find_sortable(t_stack *next, t_stack *prev, t_combine *c)
{
	c->distance_from_head = 0;
	c->distance_from_tail = 1;
	while (next)
	{
		if (next->cycle == c->cycle)
			break ;
		c->distance_from_head++;
		next = next->next;
	}
	while (prev)
	{
		if (prev->cycle == c->cycle)
			break ;
		c->distance_from_tail++;
		prev = prev->prev;
	}
	if (!next || !prev)
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

void	combine(t_info *i)
{
	t_combine	c;

	c.cycle = i->biggest_cycle;
	while (i->b_size != 0)
	{
		while (1)
		{
			if (i->b_size == 0 || !find_sortable(i->b_head, i->b_tail, &c))
				break ;
			move_to_sortable(&c, i);
			adjust_a(&c, i);
			pa(i, PA);
		}
		c.cycle--;
	}
	while (i->a_head->cc != 0)
		ra(i, RA);
}
