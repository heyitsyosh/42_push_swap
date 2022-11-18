/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/19 07:52:06 by myoshika         ###   ########.fr       */
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

void	free_nodes(t_info *i)
{
	t_stack		*s_next;
	t_command	*c_next;

	while (i->a_head)
	{
		s_next = i->a_head->next;
		free(i->a_head);
		i->a_head = s_next;
	}
	while (i->b_head)
	{
		s_next = i->b_head->next;
		free(i->b_head);
		i->b_head = s_next;
	}
	while (i->commands)
	{
		c_next = i->commands->next;
		free(i->commands);
		i->commands = c_next;
	}
}
