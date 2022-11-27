/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:32:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/28 05:46:47 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	first_adjust(t_combine *c, t_info *i)
{
	int	distance;

	distance = find_distance_to_cc(stack_min(i->a_head) i->a_head);
	if (distance <= i->a_size / 2)
		while (i->a_head != c->a_min)
			ra(i, RA);
	else
		while (i->a_head != c->a_min)
			rra(i, RRA);
}

void	adjust_a(t_combine *c, t_info *i)
{
	while (!i->a_head->part_of_lis)
		ra(i, RA);
	while (i->a_head->cycle == c->cycle)
		ra(i, RA);
}

static int	count_to_push(int cycle, t_stack *head)
{
	int	to_push;

	to_push = 0;
	while (head)
	{
		if (head->cycle == cycle)
			to_push++;
		head = head->next;
	}
	return (to_push);
}

static int	get_coordinate(int cycle, t_stack *node, t_stack *tmp)
{
	int		smaller_inputs;

	if (node->cycle != cycle)
		return (-1);
	smaller_inputs = 0;
	while (tmp)
	{
		if (tmp->input < node->input && tmp->cycle == cycle)
			smaller_inputs++;
		tmp = tmp->next;
	}
	return (smaller_inputs);
}

int	get_median_of_to_push(t_stack *head, t_combine *c)
{
	t_stack	*next;
	int		to_push_size;

	next = head;
	to_push_size = count_to_push(c->cycle, head);
	while (next)
	{
		next->to_push_cc = get_coordinate(c->cycle, next, head);
		if (next->to_push_cc == to_push_size / 2)
			c->median = next->cc;
		next = next->next;
	}
}
