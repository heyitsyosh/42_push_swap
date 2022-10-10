/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:23:47 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/10 22:52:20 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	rra(int *a, t_sizes *s)
{
	if (s->a_top < 1)
		return ;
}

void	rrb(int *b, t_sizes *s)
{
	if (s->b_top < 1)
		return ;
}

void	rrr(int *a, int *b, t_sizes *s)
{
	rra(a, s);
	rrb(b, s);
}
