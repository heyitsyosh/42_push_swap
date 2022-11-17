/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/17 12:57:24 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_min(t_stack *head)
{
	t_stack	*min;

	min = head;
	while (head)
	{
		if (head->cc < min->cc)
			min = head;
		head = head->next;
	}
	return (min);
}

void	stack_add_back(t_stack *node, t_stack **tail)
{
	if (!node || !tail)
		return ;
	(*tail)->next = node;
	node->prev = *tail;
	node->next = NULL;
	*tail = node;
}

void	stack_add_front(t_stack *node, t_stack **head, t_stack **tail)
{
	if (!node | !head | !tail)
		return ;
	else if (!*head)
	{
		node->next = NULL;
		*tail = node;
	}
	else
	{
		node->next = *head;
		(*head)->prev = node;
	}
	node->prev = NULL;
	*head = node;
}

void	free_nodes(t_save *s)
{
	t_stack		*s_next;
	t_command	*c_next;

	while (s->a_head)
	{
		s_next = s->a_head->next;
		free(s->a_head);
		s->a_head = s_next;
	}
	while (s->b_head)
	{
		s_next = s->b_head->next;
		free(s->b_head);
		s->b_head = s_next;
	}
	while (s->commands)
	{
		c_next = s->commands->next;
		free(s->commands);
		s->commands = c_next;
	}
}
