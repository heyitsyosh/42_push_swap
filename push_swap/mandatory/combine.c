/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:09:09 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/21 15:07:11 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static void	swap_if_optimal(t_info *i)
// {
// 	if (i->a_size < 2 || i->b_size < 2)
// 		return ;
// 	if (i->b_head->cc + 1 == (i->b_head->next)->cc)
// }

static void	find_closest_sortable()
{
	
}

static void	sort_cycle_into_a(t_combine *c, t_info *i)
{
	while (1)
	{
		find_closest_sortable();
		//swap_if_optimal();
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
		c.upper_limit = i->a_tail;
		c.lower_limit = i->a_head;
		sort_cycle_into_a(&c, i);
		c.cycle--;
	}
}

//find swap opportunities
//if biggest element of (division chunk?) sorted, pa -> ra
//(pa in the order or biggest to smallest)
//if smaller than median of division chunk, sort on top of stack with bigger on top

