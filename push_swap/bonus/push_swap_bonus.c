/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:23:28 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/11 07:10:40 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	sa(int *a, t_sizes *s)
{
	int	tmp;

	if (s->a_top < 1)
		return ;
	tmp = a[s->a_top];
	a[s->a_top] = a[s->a_top - 1];
	a[s->a_top - 1] = tmp;
}

void	sb(int *b, t_sizes *s)
{
	int	tmp;

	if (s->b_top < 1)
		return ;
	tmp = b[s->b_top];
	b[s->b_top] = b[s->b_top - 1];
	b[s->b_top - 1] = tmp;
}

void	ss(int *a, int *b, t_sizes *s)
{
	sa(a, s);
	sb(b, s);
}

void	pa(int *a, int *b, t_sizes *s)
{
	if (s->b_top == -1)
		return ;
	s->a_top++;
	a[s->a_top] = b[s->b_top];
	s->b_top--;
}

void	pb(int *a, int *b, t_sizes *s)
{
	if (s->a_top == -1)
		return ;
	s->b_top++;
	b[s->b_top] = a[s->a_top];
	s->a_top--;
}
