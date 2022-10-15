/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 23:10:32 by myoshika         ###   ########.fr       */
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

void	stack_add_back(t_stack *node, t_stack **head)
{
	t_stack	*last;

	if (!head || !node)
		return ;
	last = stack_last(*head);
	last->next = node;
	node->prev = last;
	node->next = NULL;
}

void	stack_add_front(t_stack *node, t_stack **head)
{
	if (!head || !node)
		return ;
	else if (!*head)
	{
		*head = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *head;
		node->prev = (*head)->prev;
		((*head)->prev)->next = node;
		(*head)->prev = node;
	}
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

//do i really need the inner parentheses around (*(s->a_head)) for example?