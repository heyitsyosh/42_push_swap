/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_utils_ii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 05:08:08 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/28 05:08:39 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*mark_a(int *cc, int cycle, t_stack *a)
{
	while (a && a->cc == cc)
	{
		a->cycle = cycle;
		a = a->next;
		(*cc)++;
	}
	return (a);
}

static void	mark_b(int *cc, int cycle, t_stack *a, t_info *i)
{
	t_stack	*next;

	next = i->b_head;
	if (!a)
	{
		if (next->cycle == -1)
			next->cycle = cycle;
		next = next->next;
	}
	while (next)
	{
		if (*cc < a->cc && next->cycle == -1)
			next->cycle = cycle;
		next = next->next;
		(*cc)++;
	}
}

void	mark_cycles(t_info *i)
{
	int		cc;
	int		cycle;
	t_stack	*next_a;

	cc = 0;
	cycle = 0;
	next_a = i->a_head;
	while (1)
	{
		next_a = mark_a(&cc, cycle, next_a);
		mark_b(&cc, cycle, next_a, i);
		cycle++;
	}
}
