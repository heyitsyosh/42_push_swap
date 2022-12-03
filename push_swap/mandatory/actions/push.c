/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:55 by myoshika          #+#    #+#             */
/*   Updated: 2022/12/04 05:03:02 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_info *i, int command)
{
	t_stack	*new_b_head;

	if (!i->b_head)
		return ;
	new_b_head = (i->b_head)->next;
	stack_add_front(i->b_head, &(i->a_head), &(i->b_tail));
	i->b_head = new_b_head;
	i->a_size++;
	i->b_size--;
	append_command(i, command);
}

void	pb(t_info *i, int command)
{
	t_stack	*new_a_head;


	if (!i->a_head)
		return ;
	new_a_head = (i->a_head)->next;
	stack_add_front(i->a_head, &(i->b_head), &(i->b_tail));
	i->a_head = new_a_head;
	i->b_size++;
	i->a_size--;
	append_command(i, command);
}
