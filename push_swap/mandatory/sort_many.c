/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/23 04:44:51 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exit_if_sorted(t_save *s)
{
	t_stack	*next;

	if (s->a_size != (s->argc - 1))
		return ;
	if (s->a_head)
		next = s->a_head->next;
	while (next)
	{
		if ((next->prev)->cc > next->cc)
			return ;
		next = next->next;
	}
	free_a_and_b(s);
	exit(EXIT_SUCCESS);
}

static bool	should_rr(int pivot_value, t_save *s)
{
	if (s->b_size <= 1)
		return (false);
	if (s->b_head->cc > pivot_value / 2)
		return (false);
	if (pivot_value != (s->argc - 1) / 2)
		return (false);
	return (true);
}

static void	divide(int pivot, int pushed, t_save *s)
{
	t_stack	*head;

	head = s->a_head;
	while (head && pushed < pivot)
	{
		head = s->a_head;
		if (head->cc < pivot)
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
		divide(pivot / 2, 0, s);
	else
		s->smallest_pivot = pivot;
}

// void	combine(int pivot, t_save *s)
// {
// 	int	cycle;

// 	cycle = 0;
// 	while (s->b_size != 0)
// 	{
		
// 	}
// }

void	sort_many(t_save *s)
{
	tmp_print(s);
	divide((s->argc - 1) / 2, 0, s);
	tmp_print(s);
	sort_few(s->a_size, s);
	//s->sorted_count = 5;
	//combine(s->smallest_pivot, s);
	tmp_print(s);
}
