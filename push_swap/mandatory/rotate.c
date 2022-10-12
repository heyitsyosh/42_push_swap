/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:53 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/12 18:49:44 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

bool	redirect_to_rotator(char *instruction, int *a, int *b, t_save *s)
{
	if (!ft_strcmp(instruction, "ra"))
		rotate(a, -1, s->a_top, NO_PRINTF);
	else if (!ft_strcmp(instruction, "rb"))
		rotate(b, -1, s->b_top, NO_PRINTF);
	else if (!ft_strcmp(instruction, "rr"))
	{
		rotate(a, -1, s->a_top, NO_PRINTF);
		rotate(b, -1, s->b_top, NO_PRINTF);
	}
	else if (!ft_strcmp(instruction, "rra"))
		rotate(a, 1, s->a_top, PRINTF);
	else if (!ft_strcmp(instruction, "rrb"))
		rotate(a, 1, s->b_top, PRINTF);
	else if (!ft_strcmp(instruction, "rrr"))
	{
		rotate(a, 1, s->a_top, NO_PRINTF);
		rotate(a, 1, s->b_top, NO_PRINTF);
	}
	else
		return (false);
	return (true);
}
