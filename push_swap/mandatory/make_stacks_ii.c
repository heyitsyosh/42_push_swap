/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:20:51 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/30 12:06:55 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	indicate_lis_nodes(t_stack *start, t_info *i)
{
	int		j;
	t_stack	*prev;

	j = 0;
	prev = start;
	start->part_of_lis = true;
	while (prev)
	{
		if (prev->cc < start->cc)
		{
			prev->part_of_lis = true;
			start = prev;
			j++;
			if (j >= i->lis->i_s_len)
				break ;
		}
		prev = prev->prev;
	}
}

static void	update_lis(t_stack *node, t_info *i)
{
	if (node->i_s_len > i->lis->i_s_len)
		i->lis = node;
}

static int	count_subsequence(t_stack *start)
{
	int		i_s_len;
	t_stack	*prev;

	i_s_len = 1;
	prev = start->prev;
	while (prev)
	{
		if (prev->cc < start->cc)
			return (prev->i_s_len + 1);
		prev = prev->prev;
	}
	return (i_s_len);
}

static int	coordinate_compression(int *sorted_streak, t_stack *node, t_info *i)
{
	t_stack	*next;
	int		smaller_inputs;

	next = i->a_head;
	smaller_inputs = 0;
	while (next)
	{
		if (next->input < node->input)
			smaller_inputs++;
		else if (next->input == node->input)
			if (next != node)
				i->has_duplicate = true;
		next = next->next;
	}
	if (*sorted_streak < smaller_inputs)
		(*sorted_streak)++;
	else
		i->sorted = false;
	return (smaller_inputs);
}

//			lis-->(longest increasing subsequence)
void	get_lis_and_compressed_coordinates(t_info *i)
{
	t_stack	*next;
	int		sorted_streak;

	if (!i->a_head)
		return ;
	next = i->a_head;
	i->lis = i->a_head;
	sorted_streak = -1;
	while (next)
	{
		next->cc = coordinate_compression(&sorted_streak, next, i);
		if (i->has_duplicate)
			return ;
		next->part_of_lis = false;
		next->i_s_len = count_subsequence(next);
		update_lis(next, i);
		next = next->next;
	}
	indicate_lis_nodes(i->lis, i);
}
