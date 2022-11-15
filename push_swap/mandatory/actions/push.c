/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:55 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/13 21:34:07 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_save *s, int command)
{
	t_stack	*new_b_head;

	if (!s->b_head)
		return ;
	new_b_head = (s->b_head)->next;
	stack_add_front(s->b_head, &(s->a_head), &(s->b_tail));
	s->b_head = new_b_head;
	s->a_size++;
	s->b_size--;
	append_command(s, command);
	tmp_print(s, "pa");
}

void	pb(t_save *s, int command)
{
	t_stack	*new_a_head;

	if (!s->a_head)
		return ;
	new_a_head = (s->a_head)->next;
	stack_add_front(s->a_head, &(s->b_head), &(s->b_tail));
	s->a_head = new_a_head;
	s->b_size++;
	s->a_size--;
	append_command(s, command);
	tmp_print(s, "pb");
}
