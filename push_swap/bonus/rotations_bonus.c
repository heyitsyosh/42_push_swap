/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:23:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/11 01:41:30 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	rotate(int *stack, int direction, int start, int end)
{
	int	i;
	int	tmp;

	if (ft_max(start, end) < 1)
		return ;
	tmp = stack[start];
	i = 0;
	while (start + i != end)
	{
		stack[start + i] = stack[start + i + direction];
		i += direction;
	}
	stack[end] = tmp;
}

bool	redirect_to_rotator(char *instruction, int *a, int *b, t_sizes *s)
{
	if (!ft_strcmp(instruction, "ra"))
		rotate(a, -1, s->a_top, 0);
	else if (!ft_strcmp(instruction, "rb"))
		rotate(b, -1, s->b_top, 0);
	else if (!ft_strcmp(instruction, "rr"))
	{
		rotate(a, -1, s->a_top, 0);
		rotate(b, -1, s->b_top, 0);
	}
	else if (!ft_strcmp(instruction, "rra"))
		rotate(a, 1, 0, s->a_top);
	else if (!ft_strcmp(instruction, "rrb"))
		rotate(a, 1, 0, s->b_top);
	else if (!ft_strcmp(instruction, "rrr"))
	{
		rotate(a, 1, 0, s->a_top);
		rotate(a, 1, 0, s->b_top);
	}
	else
		return (false);
	return (true);
}
