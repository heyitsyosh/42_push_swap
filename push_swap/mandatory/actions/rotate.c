/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:53 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/19 07:51:53 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_info *i, int command)
{
	t_stack	*new_a_head;

	if (!i->a_head || !i->a_head->next)
		return ;
	new_a_head = i->a_head->next;
	stack_add_back(i->a_head, &(i->a_tail));
	i->a_head = new_a_head;
	(i->a_head)->prev = NULL;
	if (command)
	{
		append_command(s, command);
		tmp_print(s, "ra");
	}
}

void	rb(t_info *i, int command)
{
	t_stack	*new_b_head;

	if (!i->b_head || !i->b_head->next)
		return ;
	new_b_head = i->b_head->next;
	stack_add_back(i->b_head, &(i->b_tail));
	i->b_head = new_b_head;
	(i->b_head)->prev = NULL;
	if (command)
	{
		append_command(s, command);
		tmp_print(s, "rb");
	}
}

void	rr(t_info *i, int command)
{
	ra(s, NO_COMMAND);
	rb(s, NO_COMMAND);
	append_command(s, command);
	tmp_print(s, "rr");
}
