/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:20:51 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 18:12:39 by myoshika         ###   ########.fr       */
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
		if (start->input == tmp->input)
			s->has_duplicates = true;
		else if (start->input < tmp->input)
			lmis++;
		tmp = tmp->next;
	}
	return (lmis);
}

static void	find_compressed_coordinates(t_stack	*node, t_save *s)
{
	
}

void	get_lmis_and_compressed_coordinates(t_save *s)
{
	t_stack	*tmp;

	tmp = s->a_head;
	s->min = s->a_head->input;
	s->has_duplicates = false;
	while (tmp)
	{
		tmp->lmis = count_subsequence(tmp, s);
		if (s->has_duplicates)
			break ;
		find_compressed_coordinates(tmp, s);
		tmp = tmp->next;
	}
}
