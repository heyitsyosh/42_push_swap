/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/23 05:09:31 by myoshika         ###   ########.fr       */
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
	//printf("[head:%d]\n", (*head)->input);
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
