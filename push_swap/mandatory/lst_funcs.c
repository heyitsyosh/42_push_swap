/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 03:32:29 by myoshika         ###   ########.fr       */
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

	if (!head)
		return ;
	last = stack_last(*head);
	printf("[{%p}]", head);
	printf("[%p]", last);
	fflush(stdout);
	last->next = node;
	node->prev = last;
	node->next = NULL;
}

void	stack_add_front(t_stack *node, t_stack **head)
{
	node->prev = NULL;
	if (!head)
		node->next = NULL;
	else
	{
		node->next = *head;
		(*head)->prev = node;
	}
	*head = node;
}

void	free_a_and_b(t_save *s)
{
	while (*s->a_head)
	{
		free(*(s->a_head));
		*(s->a_head) = (*(s->a_head))->next;
	}
	while (*(s->b_head))
	{
		free(*(s->b_head));
		*(s->b_head) = (*(s->a_head))->next;
	}
}

//do i really need the inner parentheses around (*(s->a_head)) for example?