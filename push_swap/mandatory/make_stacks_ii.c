/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:20:51 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/23 01:40:25 by myoshika         ###   ########.fr       */
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
			s->has_duplicate = true;
		else if (start->input < tmp->input)
			lmis++;
		tmp = tmp->next;
	}
	return (lmis);
}

static int	coordinate_compression(int *prev_cc, t_stack *node, t_save *s)
{
	t_stack	*tmp;
	int		smaller_inputs;

	tmp = s->a_head;
	smaller_inputs = 0;
	while (tmp)
	{
		if (tmp->input < node->input)
			smaller_inputs++;
		tmp = tmp->next;
	}
	if (*prev_cc < smaller_inputs)
		(*prev_cc)++;
	else
		s->sorted = false;
	return (smaller_inputs);
}

void	get_lmis_and_compressed_coordinates(t_save *s)
{
	t_stack	*next;
	int		prev_cc;

	prev_cc = -1;
	s->sorted = true;
	s->has_duplicate = false;
	if (!s->a_head)
		return ;
	next = s->a_head;
	while (next)
	{
		next->lmis = count_subsequence(next, s);
		if (s->has_duplicate)
			break ;
		next->cc = coordinate_compression(&prev_cc, next, s);
		next = next->next;
	}
}
