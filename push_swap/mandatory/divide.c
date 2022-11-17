/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:38:38 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/17 10:35:18 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	exit_if_sorted(t_save *s)
{
	t_stack	*next;

	if (s->a_size != (s->argc - 1) && s->b_size > 0)
		return ;
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

static bool	closest_non_lis_is_near_head(t_stack *head, t_stack *tail)
{
	int	len_from_head;
	int	len_from_tail;
//wait does doing head = head->next change head itself it doesnt right wth ive been wasting lines this entire code??!!
	len_from_head = 0;
	len_from_tail = 0;
	while (head)
	{
		if (head->part_of_lis)
			break ;
		len_from_head++;
		head = head->next;
	}
	while (tail)
	{
		if (tail->part_of_lis)
			break ;
		len_from_tail++;
		tail = tail->prev;
	}
	if (len_from_tail < len_from_head)
		return (false);
	return (true);
}

void	divide(int pivot, int pushed, int actions, t_save *s)
{
	int	a_size;

	a_size = s->a_size;
	// printf("[pivot:%d, pushed:%d]\n", pivot, actions);
	while (actions < a_size)
	{
		printf("[%d < %d]\n", actions, a_size);	
		fflush(stdout);
		actions++;
		if (s->a_head->cc <= pivot && !s->a_head->part_of_lis)
		{
			pb(s, PB);
			pushed++;
			if (s->first_divide && s->b_pivot && s->b_head->cc < s->b_pivot)
				rb(s, RB);
		}
		else if (s->a_size > s->lis->i_s_len)
		{
			if (closest_non_lis_is_near_head(s->a_head, s->a_tail))
				ra(s, RA);
			else
				rra(s, RRA);
			exit_if_sorted(s);
		}
	}
	s->first_divide = false;
	printf("[%d < %d - %d - 1] (%d)\n", pushed, s->argc, s->lis->i_s_len, s->argc - s->lis->i_s_len - 1);
	fflush(stdout);
	if (pushed < (s->argc - 1) - s->lis->i_s_len)
		divide(get_median(s->a_head), pushed, 0, s);
}
