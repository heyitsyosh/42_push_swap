/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:55 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/12 16:35:15 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(int *a, t_save *s)
{
	if (s->a_top < 1)
		return ;

}

void	sb(int *b, t_save *s)
{
	if (s->b_top < 1)
		return ;
}

void	ss(int *a, int *b, t_save *s)
{
	sa(a, s);
	sb(b, s);
}

void	pa(t_save *s)
{
	if (s->b_top == -1)
		return ;
	if ((s->a_head->prev)->next)
		(s->a_head->prev)->next = NULL;
	s->b_top--;
	
	s->a_top++;
}

void	pb(int *a, int *b, t_save *s)
{
	if (s->a_top == -1)
		return ;
	s->a_top++;
}
