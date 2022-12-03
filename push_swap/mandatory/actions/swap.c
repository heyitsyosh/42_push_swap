/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:09:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/12/04 05:03:44 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_info *i, int command)
{
	t_stack	*second;
	t_stack	*third;

	if (!i->a_head || !i->a_head->next)
		return ;
	second = i->a_head->next;
	third = second->next;
	if (third)
		third->prev = i->a_head;
	else
		i->a_tail = i->a_head;
	second->next = i->a_head;
	second->prev = NULL;
	(i->a_head)->prev = second;
	(i->a_head)->next = third;
	i->a_head = second;
	if (command)
		append_command(i, command);
}

void	sb(t_info *i, int command)
{
	t_stack	*second;
	t_stack	*third;

	if (!i->b_head || !i->b_head->next)
		return ;
	second = i->b_head->next;
	third = second->next;
	if (third)
		third->prev = i->b_head;
	else
		i->b_tail = i->b_head;
	second->next = i->b_head;
	second->prev = NULL;
	(i->b_head)->prev = second;
	(i->b_head)->next = third;
	i->b_head = second;
	if (command)
		append_command(i, command);
}

void	ss(t_info *i, int command)
{
	sa(i, NO_COMMAND);
	sb(i, NO_COMMAND);
	append_command(i, command);
}
