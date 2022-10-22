/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:09:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/23 05:40:13 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_save *s, char *to_print)
{
	t_stack	*second;
	t_stack	*third;

	if (!s->a_head || !s->a_head->next)
		return ;
	second = s->a_head->next;
	third = second->next;
	if (third)
		third->prev = s->a_head;
	else
		s->a_tail = s->a_head;
	second->next = s->a_head;
	second->prev = NULL;
	(s->a_head)->prev = second;
	(s->a_head)->next = third;
	s->a_head = second;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	sb(t_save *s, char *to_print)
{
	t_stack	*second;
	t_stack	*third;

	if (!s->b_head || !s->b_head->next)
		return ;
	second = s->b_head->next;
	third = second->next;
	if (third)
		third->prev = s->b_head;
	else
		s->b_tail = s->b_head;
	second->next = s->b_head;
	second->prev = NULL;
	(s->b_head)->prev = second;
	(s->b_head)->next = third;
	s->b_head = second;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	ss(t_save *s)
{
	sa(s, NULL);
	sb(s, NULL);
	ft_printf("ss");
}
