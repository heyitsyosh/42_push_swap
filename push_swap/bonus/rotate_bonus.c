/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:23:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/10 22:52:07 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	rotate(int *stack, int direction, t_sizes *s)
{
	
}

void	ra(int *a, t_sizes *s)
{
	int	i;
	int	tmp;
	int	prev;

	if (s->a_top < 1)
		return ;
	tmp = a[s->a_top];
	
}

void	rb(int *b, t_sizes *s)
{
	
	if (s->b_top < 1)
		return ;
}

void	rr(int *a, int *b, t_sizes *s)
{
	ra(a, s);
	rb(b, s);
}
