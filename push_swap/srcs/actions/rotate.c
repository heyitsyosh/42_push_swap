/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:53 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/11 09:04:47 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> //NULL
#include "push_swap.h"

void	ra(t_info *i, t_type type)
{
	t_stack	*new_a_head;

	if (!i->a_head || !i->a_head->next)
		return ;
	new_a_head = i->a_head->next;
	stack_add_back(i->a_head, &(i->a_tail));
	i->a_head = new_a_head;
	(i->a_head)->prev = NULL;
	if (type != NO_COMMAND)
		append_command(i, type);
}

void	rb(t_info *i, t_type type)
{
	t_stack	*new_b_head;

	if (!i->b_head || !i->b_head->next)
		return ;
	new_b_head = i->b_head->next;
	stack_add_back(i->b_head, &(i->b_tail));
	i->b_head = new_b_head;
	(i->b_head)->prev = NULL;
	if (type != NO_COMMAND)
		append_command(i, type);
}

void	rr(t_info *i, t_type type)
{
	ra(i, NO_COMMAND);
	rb(i, NO_COMMAND);
	append_command(i, type);
}
