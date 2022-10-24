/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/24 15:20:38 by myoshika         ###   ########.fr       */
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
	free_a_and_b(s);
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
			if (should_rr(s))
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

void	combine(t_save *s)
{
	while (s->b_size != 0)
	{
		if (s->b_head->cc + 1 == s->a_head->cc)
		{
			pa(s, PA);
		//	tmp_print(s);
		}
		else
		{
			rb(s, RB);
			//tmp_print(s);
		}
	}
}

void	sort_many(t_save *s)
{
	//tmp_print(s);
	divide(s->argc / 2, 0, s);
	//tmp_print(s);
	sort_few(s->a_size, s);
//	tmp_print(s);
	// printf("asdf\n");
	// fflush(stdout);
	combine(s);
	//tmp_print(s);
}
