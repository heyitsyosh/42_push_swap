/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:38:38 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/17 18:49:46 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	distance_to_closest_non_lis(t_stack *head, t_stack *tail)
{
	int	len_from_head;
	int	len_from_tail;

	len_from_head = 0;
	len_from_tail = 0;
	while (head)
	{
		if (head->to_push)
			break ;
		len_from_head++;
		head = head->next;
	}
	while (tail)
	{
		if (tail->to_push)
			break ;
		len_from_tail--;
		tail = tail->prev;
	}
	if ((len_from_tail - 1) * -1 < len_from_head)
		return (len_from_tail - 1);
	return (len_from_head);
}

void	ra_till_non_lis(t_save *s)
{
	int	distance;

	distance = distance_to_closest_non_lis(s->a_head, s->a_tail);
	if (distance > 0)
		while (distance-- > 0)
			ra(s, RA);
	else if (distance < 0)
		while (distance++ < 0)
			rra(s, RRA);
}

static int	count_times_to_push(int pivot, t_stack *head)
{
	int	times_to_push;

	times_to_push = 0;
	while (head)
	{
		if (head->cc <= pivot && !head->part_of_lis)
		{
			head->to_push = true;
			times_to_push++;
		}
		else
			head->to_push = false;
		head = head->next;
	}
	return (times_to_push);
}

void	divide(int pivot, int total_pushed, t_save *s)
{
	int	pushed;
	int	times_to_push;

	pushed = 0;
	times_to_push = count_times_to_push(pivot, s->a_head);
	while (pushed < times_to_push)
	{
		if (s->a_head->to_push)
		{
			pb(s, PB);
			pushed++;
			if (s->first_divide && s->b_head->cc <= s->b_pivot)
				rb(s, RB);
		}
		else
			ra_till_non_lis(s);
	}
	s->first_divide = false;
	if (pushed + total_pushed < (s->argc - 1) - s->lis->i_s_len)
		divide(get_median(s->a_head), pushed + total_pushed, s);
}
