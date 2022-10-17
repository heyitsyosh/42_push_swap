/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/17 17:53:05 by myoshika         ###   ########.fr       */
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

bool	should_rr(int pivot_value, t_save *s)
{
	if (s->b_size <= 1)
		return (false);
	if (s->b_head->cc > pivot_value / 2)
		return (false);
	if (pivot_value != (s->argc - 1) / 2)
		return (false);
	return (true);
}

void	divide(int pivot_value, t_save *s)
{
	t_stack	*next;

	next = s->a_head;
	while (next)
	{
		if (next->cc < pivot_value)
			pa(s, PA);
		else
		{
			if (should_rr(pivot_value, s))
				rr(s, RR);
			else
				ra(s, RA);
			exit_if_sorted(s);
		}
		next = next->next;
	}
	if (s->a_size < 6)
		return ;
	else
		divide(pivot_value / 2, s);
}

void	combine()
{
	
}

void	sort_many(t_save *s)
{
	divide((s->argc - 1) / 2, s);
	sort_few(s->a_size, s);
	combine();
}
