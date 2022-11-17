/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:38:38 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/17 09:22:51 by myoshika         ###   ########.fr       */
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

// static void	push_non_lis(int stack_size, t_save *s)
// {
// 	while (stack_size--)
// 	{
// 		if (!s->a_head->part_of_lis)
// 			pb(s, PB);
// 		else
// 			ra(s, RA); //optimize with rra
// 	}
// }

// static bool	head_has_more_lis_than_tail()
// {
	
// }

void	divide(int pivot, int pushed, t_save *s)
{	
	int	action;
	int	a_size;
	printf("[pivot:%d, pushed:%d]\n", pivot, action);
	action = 0;
	a_size = s->a_size;
	while (action + s->lis_count < a_size)
	{
		printf("[%d + %d < %d]\n", action, s->lis_count, a_size);
		if (s->a_head->cc < pivot && !s->a_head->part_of_lis)
		{
			pb(s, PB);
			action++;
			pushed++;
			if (s->first_divide && s->b_pivot && s->b_head->cc < s->b_pivot)
				rb(s, RB);
		}
		else
		{
			action++;
			ra(s, RA); //oprimize with how many lis elements are on each end?
			exit_if_sorted(s);
		}
	}
	s->first_divide = false;
	printf("[%d > %d + 1] (%d)\n", s->a_size, s->lis->i_s_len, s->lis->i_s_len + 1);
	if (pushed < s->argc - s->lis->i_s_len) //adjust numbers
		divide(get_median(s->a_head, s->a_size, s), pushed, s);
}
