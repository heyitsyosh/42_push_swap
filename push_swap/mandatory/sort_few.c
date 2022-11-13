/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:19:04 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/13 12:38:27 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(int first, int second, int third, t_save *s)
{
	if (first < second && second < third && first < third)
		return ;
	else if (first > second && second < third && first < third)
		sa(s, SA);
	else if (first > second && second < third && first > third)
		ra(s, RA);
	else if (first < second && second > third && first > third)
		rra(s, RRA);
	else
	{
		sa(s, SA);
		if (first > second && first > third)
			rra(s, RRA);
		else
			ra(s, RA);
	}
}

int	find_distance_to_cc(int cc, t_stack *next)
{
	int		distance;

	distance = 0;
	while (next)
	{
		if (next->cc == cc)
			break ;
		distance++;
		next = next->next;
	}
	return (distance);
}

static void	sort_five_or_four(int cc, t_save *s)
{
	int	distance;

	distance = find_distance_to_cc(cc, s->a_head);
	if (distance < 2)
		while (distance-- > 0)
			ra(s, RA);
	else
		while (s->a_size - (distance++) > 0)
			rra(s, RRA);
	pb(s, PB);
	if (s->a_size > 3)
	{
		sort_five_or_four(stack_min(s->a_head)->cc, s);
		return ;
	}
	sort_three((s->a_head)->cc, (s->a_head->next)->cc, (s->a_tail)->cc, s);
}

void	sort_few(int stack_size, t_save *s)
{
	if (stack_size >= 4)
		sort_five_or_four(stack_min(s->a_head)->cc, s);
	else if (stack_size == 3)
		sort_three((s->a_head)->cc, (s->a_head->next)->cc, (s->a_tail)->cc, s);
	else if (stack_size == 2)
		if (s->a_head > s->a_head->next)
			sa(s, SA);
	if (stack_size >= 4)
	{
		pa(s, PA);
		if (stack_size == 5)
			pa(s, PA);
	}
	s->smallest_of_sorted = s->argc - 1 - stack_size;
}
