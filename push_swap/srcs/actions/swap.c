/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:09:42 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/11 09:04:58 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> //NULL
#include "push_swap.h"

void	sa(t_info *i, t_type type)
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
	if (type)
		append_command(i, type);
}

void	sb(t_info *i, t_type type)
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
	if (type)
		append_command(i, type);
}

void	ss(t_info *i, t_type type)
{
	sa(i, NO_COMMAND);
	sb(i, NO_COMMAND);
	append_command(i, type);
}
