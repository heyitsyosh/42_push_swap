/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:09:09 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/19 08:17:08 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_if_optimal(t_info *i)
{
	if (i->a_size < 2 || i->b_size < 2)
		return ;
	if (i->b_head->cc + 1 == (i->b_head->next)->cc)
		pa_if_optimal;
}

static int	get_cycle_info(t_combine *c, t_info *i)
{
	t_stack	*next;

	next = i->b_head;
	c->largest_of_cycle = i->b_head->no_lis_cc;
	while (next->cycle == c->cycle)
	{
		if (next->no_lis_cc > c->largest_of_cycle)
			c->largest_of_cycle = next->no_lis_cc;
		next = next->next;
	}
	c->median = (c->largest_of_cycle + 1) / 2;
}

static void	sort_cycle_loop;

void	combine(t_info *i)
{
	t_combine	c;

	c.cycle = i->b_head->cycle;
	while (c.cycle-- >= 0)
	{
		get_cycle_info(&c, i);
		sort_cycle_loop();
	}
}

//find swap opportunities
//if biggest element of (division chunk?) sorted, pa -> ra
//(pa in the order or biggest to smallest)
//if smaller than median of division chunk, sort on top of stack with bigger on top

