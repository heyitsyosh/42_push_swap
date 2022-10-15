/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:53 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/16 03:46:44 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_save *s, char *to_print)
{
	t_stack	*new_a_head;

	if (!s->a_head || !s->a_head->next)
		return ;
	new_a_head = s->a_head->next;
	stack_add_back(s->a_head, &(s->a_tail));
	s->a_head = new_a_head;
	(s->a_head)->prev = NULL;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	rb(t_save *s, char *to_print)
{
	t_stack	*new_b_head;

	if (!s->b_head || !s->b_head->next)
		return ;
	new_b_head = s->b_head->next;
	stack_add_back(s->b_head, &(s->b_tail));
	s->b_head = new_b_head;
	(s->b_head)->prev = NULL;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	rr(t_save *s, char *to_print)
{
	ra(s, NULL);
	rb(s, NULL);
	ft_printf("%s\n", to_print);
}
