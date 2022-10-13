/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 16:17:34 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_last(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	stack_add_back(t_stack *node, t_stack *head)
{
	t_stack	*last;

	last = stack_last(head);
	last->next = node;
	node->prev = last;
	node->next = NULL;
}

void	free_a_and_b(t_save *s)
{
	while (s->a_head)
	{
		free(s->a_head);
		s->a_head = s->a_head->next;
	}
	while (s->b_head)
	{
		free(s->b_head);
		s->b_head = s->b_head->next;
	}
}
