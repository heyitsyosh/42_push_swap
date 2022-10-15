/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:53 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/16 01:03:25 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_save *s, char *to_print)
{
	if (!s->a_head || !s->a_head->next)
		return ;
	stack_add_back(s->a_head, &(s->a_tail));
	s->a_head = s->a_head->next;
	(s->a_head)->prev = NULL;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	rb(t_save *s, char *to_print)
{
	if (!s->b_head || !s->b_head->next)
		return ;
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	rr(t_save *s)
{
	ra(s, NULL);
	rb(s, NULL);
	ft_printf("rr");
}
