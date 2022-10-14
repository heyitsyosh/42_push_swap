/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:55 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 02:01:22 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_save *s)
{
	if (!s->b_head)
		return ;
	stack_add_front(*(s->b_head), s->a_head);
	*(s->b_head) = (*(s->b_head))->next;
	ft_printf("pa\n");
}

void	pb(t_save *s)
{
	if (!s->a_head)
		return ;
	stack_add_front(*(s->a_head), s->b_head);
	*(s->a_head) = (*(s->a_head))->next;
	ft_printf("pb\n");
}