/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:38:38 by myoshika          #+#    #+#             */
/*   Updated: 2024/11/18 07:15:31 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ra_till_non_lis(t_info *i)
{
	int	distance;

	distance = distance_to_closest_non_lis(i->a_head, i->a_tail);
	if (distance > 0)
		while (distance-- > 0)
			ra(i, RA);
	else if (distance < 0)
		while (distance++ < 0)
			rra(i, RRA);
}

static int	count_times_to_push(int pivot, t_stack *head)
{
	int	times_to_push;

	times_to_push = 0;
	while (head)
	{
		if (head->cc >= pivot && !head->part_of_lis)
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

static void	optimize_fist_divide(t_info *i)
{
	if (i->first_divide && i->b_head->cc > i->b_pivot)
	{
		i->b_head->cycle--;
		rb(i, RB);
	}
}

void	divide(int pivot, int total_pushed, int cycle, t_info *i)
{
	int	pushed;
	int	times_to_push;

	pushed = 0;
	times_to_push = count_times_to_push(pivot, i->a_head);
	while (pushed < times_to_push)
	{
		if (i->a_head->to_push)
		{
			pb(i, PB);
			i->b_head->cycle = cycle;
			pushed++;
			optimize_fist_divide(i);
		}
		else
			ra_till_non_lis(i);
	}
	i->first_divide = false;
	if (pushed + total_pushed < (i->argc - 1) - i->lis->i_s_len)
		divide(get_median(i->a_head), pushed + total_pushed, ++cycle, i);
	else
		i->biggest_cycle = cycle;
}
