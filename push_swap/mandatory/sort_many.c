/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/15 20:47:51 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	should_rr(int pivot, t_save *s)
{
	if (s->b_size <= 1)
		return (false);
	if (pivot != s->argc / 2)
		return (false);
	if ()
	return (true);
}

static void	divide(int pivot, int sorted, t_save *s)
{
	while (s->a_head && sorted < pivot)
	{
		if (s->a_head->cc < pivot && !s->a_head->part_of_lis)
		{
			pb(s, PB);
			sorted++;
		}
		else
		{
			if (s->a_head->part_of_lis)
				sorted++;
			if (should_rr(pivot, s))
				rr(s, RR);
			else
				ra(s, RA);
			exit_if_sorted(s);
		}
	}
	if (s->a_size > s->lis->i_s_len + 1)
		divide(sorted + (s->argc - sorted) / 2, sorted, s);
}

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
}
