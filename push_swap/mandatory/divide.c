/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:38:38 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/16 22:03:33 by myoshika         ###   ########.fr       */
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

static void	push_non_lis(int stack_size, t_save *s)
{
	while (stack_size--)
	{
		if (!s->a_head->part_of_lis)
			pb(s, PB);
		else
			ra(s, RA); //optimize with rra
	}
}

//find opportunities for rr and split stack b
static void	optimize_first_divide()
{
	
}

static bool	head_has_more_lis_than_tail()
{
	
}

void	divide(int pivot, int pushed, t_save *s)
{
	s->b_pivot(get_third_quartile(a_))
	while (s->a_head && pushed + s->lis_count < pivot)
	{
		// tmp_print(s, NULL);
		// printf("[pivot:%d, pushed:%d]\n", pivot, pushed);
		// fflush(stdout);
		if (s->a_head->cc < pivot && !s->a_head->part_of_lis)
		{
			pb(s, PB);
			pushed++;
			if (s->first_divide)
				
		}
		else
		{
			ra(s, RA); //oprimize with how many lis elements are on each end?
			exit_if_sorted(s);
		}
	}
	s->first_divide = false;
	if (pushed < s->argc - s->lis->i_s_len - 1) //adjust numbers
		divide(find_median(s->a_head, s->a_size, s), pushed, s);
}
