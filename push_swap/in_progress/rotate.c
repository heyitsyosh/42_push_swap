/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:43:53 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 14:26:26 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(int *stack, int direction, int start, int end)
{
	
}

static void	rev_rotate()
{
	
}

bool	redirect_to_rotator(char *instruction, int *a, int *b, t_save *s)
{
	if (!ft_strcmp(instruction, "ra"))
		rotate(s->a_head, NO_PRINTF);
	else if (!ft_strcmp(instruction, "rb"))
		rotate(b, -1, s->b_top, NO_PRINTF);
	else if (!ft_strcmp(instruction, "rr"))
	{
		rotate(a, -1, s->a_top, NO_PRINTF);
		rotate(b, -1, s->b_top, NO_PRINTF);
		ft_printf("rr\n");
	}
	else if (!ft_strcmp(instruction, "rra"))
		rev_rotate(a, 1, s->a_top, PRINTF);
	else if (!ft_strcmp(instruction, "rrb"))
		rev_rotate(a, 1, s->b_top, PRINTF);
	else if (!ft_strcmp(instruction, "rrr"))
	{
		rev_rotate(a, 1, s->a_top, NO_PRINTF);
		rev_rotate(a, 1, s->b_top, NO_PRINTF);
		ft_printf("rrr\n");
	}
	else
		return (false);
	return (true);
}
