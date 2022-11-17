/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:09:09 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/17 23:23:31 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	combine(t_save *s)
{
	s->cycle = s->b_head->cycle;
	while (s->cycle-- >= 0)
	{
		
	}
}

//swap opportunities
//if biggest element of (division chunk?) sorted, pa -> ra
//(pa in the order or biggest to smallest)
//if smaller than median of division chunk, sort on top of stack with bigger on top