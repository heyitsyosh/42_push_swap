/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:19:04 by myoshika          #+#    #+#             */
/*   Updated: 2022/12/06 17:13:22 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three(int first, int second, int third, t_info *i)
{
	if (first < second && second < third && first < third)
		return ;
	else if (first > second && second < third && first < third)
		sa(i, SA);
	else if (first > second && second < third && first > third)
		ra(i, RA);
	else if (first < second && second > third && first > third)
		rra(i, RRA);
	else
	{
		sa(i, SA);
		if (first > second && first > third)
			rra(i, RRA);
		else
			ra(i, RA);
	}
}

int	distance_from_top(int cc, t_stack *next)
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

int	distance_from_bottom(int cc, t_stack *prev)
{
	int		distance;

	distance = 0;
	while (prev)
	{
		if (prev->cc == cc)
			break ;
		distance++;
		prev = prev->prev;
	}
	return (distance);
}

static void	sort_five_or_four(int cc, t_info *i)
{
	int	distance;

	distance = distance_from_top(cc, i->a_head);
	if (distance < 2)
		while (distance-- > 0)
			ra(i, RA);
	else
		while (i->a_size - (distance++) > 0)
			rra(i, RRA);
	pb(i, PB);
	if (i->a_size > 3)
	{
		sort_five_or_four(stack_min(i->a_head)->cc, i);
		return ;
	}
	sort_three((i->a_head)->cc, (i->a_head->next)->cc, (i->a_tail)->cc, i);
}

void	sort_few(int stack_size, t_info *i)
{
	if (stack_size >= 4)
		sort_five_or_four(stack_min(i->a_head)->cc, i);
	else if (stack_size == 3)
		sort_three((i->a_head)->cc, (i->a_head->next)->cc, (i->a_tail)->cc, i);
	else if (stack_size == 2)
		if ((i->a_head)->cc > (i->a_head->next)->cc)
			sa(i, SA);
	if (stack_size >= 4)
	{
		pa(i, PA);
		if (stack_size == 5)
			pa(i, PA);
	}
}
