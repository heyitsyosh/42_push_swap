/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:32:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/27 17:50:09 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	adjust_a(t_combine *c, t_info *i)
{
	t_stack	*a_max;

	while (!i->a_head->part_of_lis)
		ra(i, RA);
	a_max = min(i->a_head);
	if (!c->smallest_of_cycle || a_max->cc )
	while (i->a_head->cc == (c->b_min)->cc + 1)
		ra(i, RA);
}

//mark nodes to push
void	set_info(t_combine *c, t_info *i)
{

	
}
//fix so last 2 cycles have quadrant split
// coorinate compress for cycle 0 and 1