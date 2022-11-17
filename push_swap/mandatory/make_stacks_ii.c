/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:20:51 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/17 22:59:00 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	indicate_lis_nodes(t_stack *start, t_save *s)
{
	int		i;
	t_stack	*prev;

	i = 0;
	prev = start;
	start->part_of_lis = true;
	start->sorted = true;
	while (prev)
	{
		if (prev->cc < start->cc)
		{
			prev->part_of_lis = true;
			prev->sorted = true;
			start = prev;
			i++;
			if (i >= s->lis->i_s_len)
				break ;
		}
		prev = prev->prev;
	}
}

static void	update_lis(t_stack *node, t_save *s)
{
	if (node->i_s_len > s->lis->i_s_len)
		s->lis = node;
	else if (node->i_s_len == s->lis->i_s_len)
		if (node->cc > s->lis->cc)
			s->lis = node;
}

static int	count_subsequence(t_stack *start)
{
	int		i_s_len;
	t_stack	*prev;

	i_s_len = 1;
	prev = start->prev;
	while (prev)
	{
		if (start->cc > prev->cc)
			return (prev->i_s_len + 1);
		prev = prev->prev;
	}
	return (i_s_len);
}

static int	coordinate_compression(int *sorted_streak, t_stack *node, t_save *s)
{
	t_stack	*next;
	int		smaller_inputs;

	next = s->a_head;
	smaller_inputs = 0;
	while (next)
	{
		if (next->input < node->input)
			smaller_inputs++;
		else if (next->input == node->input)
			if (next != node)
				s->has_duplicate = true;
		next = next->next;
	}
	if (*sorted_streak < smaller_inputs)
		(*sorted_streak)++;
	else
		s->sorted = false;
	return (smaller_inputs);
}

//			lis-->(longest increasing subsequence)
void	get_lis_and_compressed_coordinates(t_save *s)
{
	t_stack	*next;
	int		sorted_streak;

	if (!s->a_head)
		return ;
	next = s->a_head;
	s->lis = s->a_head;
	sorted_streak = -1;
	while (next)
	{
		next->cc = coordinate_compression(&sorted_streak, next, s);
		if (s->has_duplicate)
			return ;
		next->sorted = false;
		next->part_of_lis = false;
		next->i_s_len = count_subsequence(next);
		update_lis(next, s);
		next = next->next;
	}
	indicate_lis_nodes(s->lis, s);
}
