/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:09:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 23:54:20 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_save *s, char *to_print)
{
	t_stack	*third;

	if (!s->a_head || !s->a_head->next)
		return ;
	third = ((s->a_head)->next)->next;
	stack_add_front(s->a_head->next, &(s->a_head), &(s->a_tail));
	(s->a_head->next)->next = third;
	if (third)
		third->prev = (s->a_head->next)->next;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	sb(t_save *s, char *to_print)
{
	t_stack	*third;

	if (!s->b_head || !s->b_head->next)
		return ;
	third = ((s->b_head)->next)->next;
	stack_add_front(s->b_head->next, &(s->b_head), &(s->b_tail));
	(s->b_head->next)->next = third;
	if (third)
		third->prev = (s->b_head->next)->next;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	ss(t_save *s)
{
	sa(s, NULL);
	sb(s, NULL);
	ft_printf("ss");
}
