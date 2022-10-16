/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/16 03:47:21 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	free_a_and_b(t_save *s)
{
	t_stack	*next;

	while (s->a_head)
	{
		next = s->a_head->next;
		free(s->a_head);
		s->a_head = next;
	}
	while (s->b_head)
	{
		next = s->b_head->next;
		free(s->b_head);
		s->b_head = next;
	}
}