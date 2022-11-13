/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/13 13:05:52 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_if_sorted(t_save *s)
{
	t_stack	*next;

	if (s->a_size != (s->argc - 1) && s->b_size > 0)
		return ;
	next = NULL;
	if (s->a_head)
		next = s->a_head->next;
	while (next)
	{
		if ((next->prev)->cc > next->cc)
			return ;
		next = next->next;
	}
	free_nodes(s);
	exit(EXIT_SUCCESS);
}

static bool	should_rr(t_save *s)
{
	if (s->b_size <= 1)
		return (false);
	if (s->b_head->cc > s->b_size / 2)
		return (false);
	return (true);
}

static void	divide(int pivot, int pushed, t_save *s)
{
	while (s->a_head && pushed < pivot)
	{
		ss_if_optimal(s);
		if (s->a_head->cc < pivot)
		{
			pb(s, PB);
			pushed++;
		}
		else
		{
			if (should_rr(s))
				rr(s, RR);
			else
				ra(s, RA);
			exit_if_sorted(s);
		}
	}
	if (s->a_size > 5)
		divide(pushed + (s->argc - pushed) / 2, pushed, s);
	else
		s->smallest_pivot = pivot;
}

void	combine(t_save *s)
{
	while (s->b_size != 0)
	{
		if (s->smallest_of_sorted - 1 == s->b_head->cc)
		{
			pa(s, PA);
			s->smallest_of_sorted--;
		}
		else
			find_combo(s);
	}
}

void	sort_many(t_save *s)
{
	divide(s->argc / 2, 0, s);
	sort_few(s->a_size, s);
	combine(s);
}
