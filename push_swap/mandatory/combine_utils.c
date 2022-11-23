/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:32:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/23 18:42:25 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_first_adjust_distance(t_combine *c, t_info *i)
{
	t_stack	*next;
	int		distance;

	next = i->a_head;
	distance = 0;
	while (1)
	{
		distance++;
		if (next->cc > c->largest_of_cycle->cc
			if (c->largest_of_cycle->cc + 1 == i->a_size + i->b_size)
				break ;
			&& next->cc < c->largest_of_cycle->cc)

		next = next->next;
	}
	return (distance);
}

static void	first_adjust(t_combine *c, t_info *i)
{
	int		distance;

	distance = get_first_adjust_distance(c, i);
	if (distance <= i->a_size / 2)
		while (distance--)
			ra(i, RA);
	else
	{
		distance = i->a_size - distance;
		while (distance--)
			rra(i, RRA);
	}
}

void	adjust_a(t_combine *c, t_info *i)
{
	if (c->cycle == i->b_head->cycle)
		first_adjust(c, i);
	else
	{
		while (!i->a_head->part_of_lis)
			ra(i, RA);
		while (i->a_head->cc > (c->largest_of_cycle)->cc)
			ra(i, RA);
	}
}

int	get_cycle_info(t_combine *c, t_info *i)
{
	t_stack	*next;

	next = i->b_head;
	c->largest_of_cycle = i->b_head;
	while (next->cycle == c->cycle)
	{
		if (next->no_lis_cc > (c->largest_of_cycle)->no_lis_cc)
			(c->largest_of_cycle) = next;
		next = next->next;
	}
}
