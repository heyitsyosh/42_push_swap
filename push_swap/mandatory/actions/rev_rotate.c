/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:48:02 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/23 01:30:34 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_save *s, char *to_print)
{
	t_stack	*new_a_tail;

	if (!s->a_head || !s->a_head->next)
		return ;
	new_a_tail = (s->a_tail)->prev;
	stack_add_front(s->a_tail, &(s->a_head), &(s->a_tail));
	new_a_tail->next = NULL;
	s->a_tail = new_a_tail;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	rrb(t_save *s, char *to_print)
{
	t_stack	*new_b_tail;

	if (!s->b_head || !s->b_head->next)
		return ;
	new_b_tail = (s->b_tail)->prev;
	stack_add_front(s->b_tail, &(s->b_head), &(s->b_tail));
	new_b_tail->next = NULL;
	s->b_tail = new_b_tail;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	rrr(t_save *s, char *to_print)
{
	rra(s, NULL);
	rrb(s, NULL);
	ft_printf("%s\n", to_print);
}
