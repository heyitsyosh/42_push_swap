/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:48:02 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/11 09:04:37 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h> //NULL
#include "push_swap.h"

void	rra(t_info *i, t_type type)
{
	t_stack	*new_a_tail;

	if (!i->a_head || !i->a_head->next)
		return ;
	new_a_tail = (i->a_tail)->prev;
	stack_add_front(i->a_tail, &(i->a_head), &(i->a_tail));
	new_a_tail->next = NULL;
	i->a_tail = new_a_tail;
	if (type != NO_COMMAND)
		append_command(i, type);
}

void	rrb(t_info *i, t_type type)
{
	t_stack	*new_b_tail;

	if (!i->b_head || !i->b_head->next)
		return ;
	new_b_tail = (i->b_tail)->prev;
	stack_add_front(i->b_tail, &(i->b_head), &(i->b_tail));
	new_b_tail->next = NULL;
	i->b_tail = new_b_tail;
	if (type != NO_COMMAND)
		append_command(i, type);
}

void	rrr(t_info *i, t_type type)
{
	rra(i, NO_COMMAND);
	rrb(i, NO_COMMAND);
	append_command(i, type);
}
