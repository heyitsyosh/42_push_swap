/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:19:04 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/16 06:52:15 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(int first, int second, int third, t_save *s)
{
	if (first == 1 && second == 0 && third == 2)
		sa(s, SA);
	else if (first == 2 && second == 0 && third == 1)
		ra(s, RA);
	else if (first == 1 && second == 2 && third == 0)
		rra(s, RRA);
	else
	{
		sa(s, SA);
		if (first == 2)
			rra(s, RRA);
		else
			ra(s, RA);
	}
}

int	find_distance_to_cc(int cc, t_save *s)
{
	int		distance;
	t_stack	*next;

	distance = 0;
	next = s->a_head;
	while (next)
	{
		if (next->cc == cc)
			break ;
		distance++;
		next = next->next;
	}
	return (distance);
}

void	sort_five_or_four(t_save *s)
{
	int	distance;

	distance = find_distance_to_cc(0, s);
	if (distance < 2)
	{
		while (distance-- > 0)
			ra(s, RA);
	}
	else
	{
		while (distance-- > 0)
			rra(s, RA);
	}
	pb(s, PB);
	if (s->a_size > 3)
		sort_five_or_four(s);
	sort_three((s->a_head)->cc, (s->a_head->next)->cc, (s->a_tail)->cc, s);
	pa(s, PA);
	pa(s, PA);
}

void	sort_few(int argc, t_save *s)
{
	if (argc - 1 >= 4)
		sort_five_or_four(s);
	else if (argc - 1 == 3)
		sort_three((s->a_head)->cc, (s->a_head->next)->cc, (s->a_tail)->cc, s);
	else if (argc - 1 == 2)
		if (s->a_head > s->a_head->next)
			sa(s, SA);
}
