/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/21 17:24:50 by myoshika         ###   ########.fr       */
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

static int	divide(int pivot_value, t_save *s)
{
	t_stack	*next;
	int		ret;

	next = s->a_head;
	while (next && s->a_size > 5)
	{
		if (next->cc <= pivot_value)
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
	if (s->a_size > 5)
		ret = divide(pivot_value / 2, s);
	else
		s->smallest_pivot = pivot_value;
}

void	analyze_top_of_b(t_stack *s)
{
	
}

void	combine(t_stack *s)
{
	analyze_top_of_b(s);
}

void	sort_many(t_save *s)
{
	divide((s->argc - 1) / 2, s);
	sort_few(s->a_size, s);
	combine(s);
}
