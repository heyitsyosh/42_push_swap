/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_utils_ii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 05:08:08 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/28 16:34:34 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*mark_a(int *cc, int chunk, t_stack *a)
{
	while (a && a->cc == *cc)
	{
		a->chunk = chunk;
		(*cc)++;
		a = a->next;
	}
	return (a);
}

static void	mark_b(int *cc, int chunk, t_stack *a, t_info *i)
{
	t_stack	*next;

	next = i->b_head;
	if (!a)
	{
		while (next)
		{
			if (next->chunk == -1)
				next->chunk = chunk;
			next = next->next;
		}
	}
	while (next)
	{
		if (*cc < a->cc && next->chunk == -1)
		{
			next->chunk = chunk;
			(*cc)++;
		}
		next = next->next;
	}
}

int	mark_chunks(t_info *i)
{
	int		cc;
	int		chunk;
	t_stack	*next_a;

	cc = 0;
	chunk = 0;
	next_a = i->a_head;
	while (next_a)
	{
		next_a = mark_a(&cc, chunk, next_a);
		chunk++;
		mark_b(&cc, chunk, next_a, i);
		chunk++;
	}
	return (chunk);
}
