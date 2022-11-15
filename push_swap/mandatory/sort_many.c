/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/15 16:55:25 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	pb_if_not_part_of_lis(int b_pivot, t_save *s)
{
	if (s->a_head->part_of_lis)
	{
		pb(s, PB);
		if (s->b_head->cc <= b_pivot)
			rb(s, RB);
		return (true);
	}
	return (false);
}

void	leave_lis_push_others(t_save *s)
{
	int	b_pivot;

	b_pivot = (s->argc - s->lis->i_s_len) / 2;
	while (s->a_head != s->lis)
	{
		if (!pb_if_not_part_of_lis(b_pivot, s))
			ra(s, RA); //add rr optimization?
	}
	ra(s, RA);
	while (s->a_head != s->lis_end)
	{
		if (s->a_head > s->lis)
		{
			ra(s, RA);
			s->lis = s->a_tail;
		}
		else
			pb_if_not_part_of_lis(b_pivot, s);
	}
}

void	sort_many(t_save *s)
{
	// printf("[b pivot:%d]\n", (s->argc - 1 - s->lis->i_s_len) / 2);
	// printf("[lds:%d | len:%d]\n", s->lis->cc, s->lis->i_s_len);
	// printf("[lds:%d]\n", s->lis_end->cc);
	// printf("asdf");
	// fflush(stdout);
	leave_lis_push_others(s);
}
