/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:32:37 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/28 03:50:45 by myoshika         ###   ########.fr       */
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

static int	get_coordinate(t_stack *node, t_stack *tmp)
{
	int		smaller_inputs;

	if (!node->to_push)
		return (-1);
	smaller_inputs = 0;
	while (tmp)
	{
		if (tmp->input < node->input && !tmp->to_push)
			smaller_inputs++;
		tmp = tmp->next;
	}
	return (smaller_inputs);
}

int	get_median_of_to_push(int to_push_size, t_stack *head, t_combine *c)
{
	t_stack	*next;

	next = head;
	while (next)
	{
		next->to_push_cc = get_coordinate(next, head);
		if (next->to_push_cc == to_push_size / 2)
			c->median = next;
		next = next->next;
	}
}

// int	indicate_to_push(t_combine *c, t_info *i)
// {
// 	t_stack	*next;
// 	int		to_push;

// 	next = i->b_head;
// 	to_push = 0;
// 	while (next)
// 	{ //adjust for when smaller bound and larger bounds are irregular?
// 		if (c->larger_bound->cc > c->smaller_bound->cc && next->cc > )
// 		{
// 			next->to_push = true;
// 			to_push++;
// 		}
// 		else if (next->cc > c->smaller_bound->cc && next->cc < c->larger_bound->cc)
// 		{
// 			next->to_push = true;
// 			to_push++;
// 		}
// 		else
// 			next->to_push = false;
// 		next = next->next;
// 	}
// 	return (to_push);
// }
