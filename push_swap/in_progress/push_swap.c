/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:55 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 14:27:40 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(int *a, t_save *s, bool need_to_print)
{
	if (s->a_top < 1)
		return ;
	if (need_to_print)
		ft_printf("sa\n");
}

void	sb(int *b, t_save *s, bool need_to_print)
{
	if (s->b_top < 1)
		return ;
	if (need_to_print)
		ft_printf("sb\n");
}

void	ss(int *a, int *b, t_save *s)
{
	sa(a, s, NO_PRINTF);
	sb(b, s, NO_PRINTF);
	ft_printf("pb\n");
}

void	pa(t_save *s)
{
	if (s->b_top == -1)
		return ;
	if ((s->a_head->prev)->next)
		(s->a_head->prev)->next = NULL;
	s->b_top--;
	
	s->a_top++;
	ft_printf("pa\n");
}

void	pb(int *a, int *b, t_save *s)
{
	if (s->a_top == -1)
		return ;
	s->a_top++;
	ft_printf("pb\n");
}
