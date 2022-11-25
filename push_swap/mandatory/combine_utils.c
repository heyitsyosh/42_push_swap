/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:32:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/25 10:53:44 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_first_adjust_distance(t_info *i)
{
	int		distance;
	t_stack	*tmp;
	t_stack	*node_to_move_to_top;

	distance = 0;
	tmp = i->a_head;
	node_to_move_to_top = i->lis;
	if (i->lis->cc + 1 == i->a_size + i->b_size)
	{
		while (node_to_move_to_top->prev)
			if (node_to_move_to_top->prev->cc + 1 == node_to_move_to_top->cc)
				node_to_move_to_top = node_to_move_to_top->prev;
	}
	while (1)
	{
		if (tmp == node_to_move_to_top)
			break ;
		distance++;
		tmp = tmp->next;
	}
	return (distance);
}

static void	first_adjust(t_info *i)
{
	int		distance;

	distance = get_first_adjust_distance(i);
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
		first_adjust(i);
	else
	{
		while (!i->a_head->part_of_lis)
			ra(i, RA);
		while (i->a_head->cc > (c->largest_of_cycle)->cc)
			ra(i, RA);
	}
}

void	get_cycle_info(t_combine *c, t_info *i)
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
