/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:38:38 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/16 00:01:48 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	exit_if_sorted(t_save *s)
{
	t_stack	*next;

	if (s->a_size != (s->argc - 1) && s->b_size > 0)
		return ;
	next = s->a_head->next;
	while (next)
	{
		if ((next->prev)->cc > next->cc)
			return ;
		next = next->next;
	}
	free_nodes(s);
	exit(EXIT_SUCCESS);
}

int	no_lis_coordinate_compression(t_stack *node, t_stack *head)
{
	t_stack	*next;
	int		smaller_inputs;

	if (node->part_of_lis)
		return (-1);
	next = head;
	smaller_inputs = 0;
	while (next)
	{
		if (next->input < node->input && !next->part_of_lis)
			smaller_inputs++;
		next = next->next;
	}
	return (smaller_inputs);
}

int	find_median(t_stack *head, int stack_size, t_save *s)
{
	t_stack	*next;
	int		no_lis_stack_size;

	next = head;
	no_lis_stack_size = 0;
	while (next)
	{
		next->no_lis_cc = no_lis_coordinate_compression(next, head);
		if (next->no_lis_cc != -1)
			no_lis_stack_size++;
		next = next->next;
	}
	next = head;
	while (next)
	{
		if (next->no_lis_cc == no_lis_stack_size / 2)
			break ;
		next = next->next;
	}
	s->lis_count = stack_size - no_lis_stack_size;
	return (next->cc);
}

static void	push_non_lis(int stack_size, t_save *s)
{
	while (stack_size--)
	{
		if (!s->a_head->part_of_lis)
			pb(s, PB);
		else
			ra(s, RA);
	}
}

void	divide(int pivot, int pushed, t_save *s)
{
	while (s->a_head && pushed + s->lis_count < pivot)
	{
		// tmp_print(s, NULL);
		printf("[pivot:%d, pushed:%d]\n", pivot, pushed);
		fflush(stdout);
		if (s->a_head->cc < pivot && !s->a_head->part_of_lis)
		{
			pb(s, PB);
			pushed++;
		}
		else
		{
			if (pivot > (s->a_size- s->lis_count) / 2)
				rra(s, RRA);
			else
				ra(s, RA);
			exit_if_sorted(s);
		}
	}
	if (s->a_size > s->lis->i_s_len + 1 + 2) //adjust numbers
		divide(find_median(s->a_head, s->a_size, s), pushed, s);
	else
		push_non_lis(s->a_size, s);
}
