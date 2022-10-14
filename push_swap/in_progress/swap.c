/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:09:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/14 14:13:59 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_save *s, char	*to_print)
{
	t_stack	tmp;

	if (!s->a_head || !s->a_head->prev)
		return ;
	tmp.next = s->a_head->next->next;
	stack_add_front(s->a_head->prev, s->a_head);
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	sb(t_save *s, char	*to_print)
{
	t_stack	tmp;

	if (!s->b_head || !s->b_head->prev)
		return ;
	tmp.prev = s->b_head->;
	stack_add_front(s->b_head->prev, s->b_head);
	
	if (to_print)
		ft_printf("%s\n", to_print);
}

void	ss(t_save *s)
{
	sa(s, NULL);
	sb(s, "ss");
}
