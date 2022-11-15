/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/15 21:56:13 by myoshika         ###   ########.fr       */
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

static void	divide(int pivot, int actions, int confirmed_size, t_save *s)
{
	int	a_size;

	a_size = s->a_size;
	while (s->a_head && s-> < pivot && actions < a_size)
	{
		// tmp_print(s, NULL);
		fflush(stdout);
		if (s->a_head->cc < pivot && !s->a_head->part_of_lis)
		{
			pb(s, PB);
			pushed++;
		}
		else
		{
			actions++;
			ra(s, RA);
			exit_if_sorted(s);
		}
	}
	if (s->a_size > s->lis->i_s_len + 1)
		divide(pivot + (pivot + 1) / 2, 0, confirmed_size, s);
}

// int	swap_opportunity();

// void	combine(t_save *s)
// {
// 	int	tail_cost;
// 	int	swap_opportunity;

// 	while (s->b_size != 0)
// 	{
// 		swap_opportunity(s);
// 	}
// }

void	sort_many(t_save *s)
{
	tmp_print_lis(s);
	tmp_print_bool(s);
	tmp_print(s, NULL);
	printf("[b pivot:%d]\n", s->argc / 2);
	printf("[lds:%d | len:%d]\n", s->lis->cc, s->lis->i_s_len);
	printf("[lds:%d]\n", s->lis_end->cc);
	fflush(stdout);
	divide(s->argc / 2, 0, 0, s);
	//combine(s);
}
