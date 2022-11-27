/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:38:38 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/28 04:09:28 by myoshika         ###   ########.fr       */
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

void	ra_till_non_lis(t_info *i)
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

void	divide(int pivot, int total_pushed, t_info *i)
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
			pushed++;
			if (i->first_divide && i->b_head->cc >= i->b_pivot)
				rb(i, RB);
		}
		else
			ra_till_non_lis(i);
	}
	i->first_divide = false;
	if (pushed + total_pushed < (i->argc - 1) - i->lis->i_s_len)
		divide(get_median(i->a_head), pushed + total_pushed, i);
}
