/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/15 17:26:06 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	pb_if_not_part_of_lis(int b_pivot, t_save *s)
{
	if (!s->a_head->part_of_lis)
	{
		pb(s, PB);
		if (s->b_head->cc <= b_pivot)
			rb(s, RB);
		return (true);
	}
	return (false);
}

void	leave_lis_push_others(t_save *s)
{
	int	b_pivot;

	b_pivot = (s->argc - s->lis->i_s_len) / 2;
	while (s->a_head != s->lis)
	{
		if (!pb_if_not_part_of_lis(b_pivot, s))
			ra(s, RA); //add rr optimization?
	}
	ra(s, RA);
	while (s->a_head != s->lis_end)
	{
		if (s->a_head > s->lis)
		{
			ra(s, RA);
			s->lis = s->a_tail;
		}
		else
			pb_if_not_part_of_lis(b_pivot, s);
	}
}

void	tmp_print_lis(t_save *s, char *command)
{
	t_stack *next;
	next = s->a_head;
	if (command)
		printf("%s\n", command);
	printf("a:");
	while (next)
	{
		printf("[%d]", next->i_s_len);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
	next = s->b_head;
	printf("b:");
	while (next)
	{
		printf("[%d]", next->i_s_len);
		fflush(stdout);
		next = next->next;
	}
	printf("\n------------------------------\n");
	fflush(stdout);
}

void	tmp_print_bool(t_save *s, char *command)
{
	t_stack *next;
	next = s->a_head;
	if (command)
		printf("%s\n", command);
	printf("a:");
	while (next)
	{
		printf("[%d]", next->part_of_lis != 0);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
	next = s->b_head;
	printf("b:");
	while (next)
	{
		printf("[%d]", next->part_of_lis != 0);
		fflush(stdout);
		next = next->next;
	}
	printf("\n------------------------------\n");
	fflush(stdout);
}


void	sort_many(t_save *s)
{
	tmp_print_lis(s, NULL);
	tmp_print_bool(s, NULL);
	tmp_print(s, NULL);
	printf("[b pivot:%d]\n", (s->argc - 1 - s->lis->i_s_len) / 2);
	printf("[lds:%d | len:%d]\n", s->lis->cc, s->lis->i_s_len);
	printf("[lds:%d]\n", s->lis_end->cc);
	fflush(stdout);
	leave_lis_push_others(s);
}
