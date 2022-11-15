/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/15 20:41:58 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	pb_if_not_part_of_lis(t_save *s)
{
	if (!s->a_head->part_of_lis)
	{
		pb(s, PB);
		if (s->b_head->cc <= b_pivot)
			rb(s, RB);
		return (true);
	}
	return (false);
}

void	leave_lis_pb_others(t_save *s)
{
	while (s->a_head != s->lis)
	{
		if (!pb_if_not_part_of_lis(s))
			ra(s, RA);
	}
	ra(s, RA);
	while (s->a_head != s->lis_end)
	{
		if (s->a_head->cc > s->lis->cc)
		{
			ra(s, RA);
			s->lis = s->a_tail;
		}
		else
			pb_if_not_part_of_lis(s);
	}
}

static bool	should_rr(int pivot, t_save *s)
{
	if (s->b_size <= 1)
		return (false);
	if (pivot != )
		return (false);
	return (true);
}

static void	divide(int pivot, int pushed, t_save *s)
{
	while (s->a_head && pushed < pivot)
	{
		if (s->a_head->cc < pivot && !s->a_head->part_of_lis)
		{
			pb(s, PB);
			pushed++;
		}
		else
		{
			if (should_rr(pivot, s))
				rr(s, RR);
			else
				ra(s, RA);
			exit_if_sorted(s);
		}
	}
	if (s->a_size > 5)
		divide(pushed + (s->argc - pushed) / 2, pushed, s);
}

// void	sort_b_into_a(t_save *s)
// {
// 	if (s->b_head->cc > s->lis->cc)
// }

void	sort_many(t_save *s)
{
	// tmp_print_lis(s, NULL);
	// tmp_print_bool(s, NULL);
	// tmp_print(s, NULL);
	// printf("[b pivot:%d]\n", (s->argc - 1 - s->lis->i_s_len) / 2);
	// printf("[lds:%d | len:%d]\n", s->lis->cc, s->lis->i_s_len);
	// printf("[lds:%d]\n", s->lis_end->cc);
	// fflush(stdout);
	divide(s->argc / 2, 0, s);
	leave_lis_pb_others(s);
	find_b_median(s);
	sort_b_into_a(s);
}
