/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:20:51 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 14:59:46 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_subsequence(t_stack *start, t_save *s)
{
	int		lmis;
	t_stack	*tmp;

	lmis = 0;
	tmp = start->next;
	while (tmp)
	{
		if (start->i == tmp->i)
			s->has_duplicates = true;
		else if (start->i < tmp->i)
			lmis++;
		tmp = tmp->next;
	}
	return (lmis);
}

void	get_lmis(t_save *s)
{
	t_stack	*tmp;

	tmp = s->a_head;
	s->has_duplicates = false;
	while (tmp)
	{
		tmp->lmis = count_subsequence(tmp, s);
		if (s->has_duplicates)
			break ;
		tmp = tmp->next;
	}
}

void	adjust_compressed_coordinates(t_save *s)
{
	t_stack	*tmp;

	tmp = s->a_head;
	while (tmp)
	{
		tmp->i += s->min;
		tmp = tmp->next;
	}
}
