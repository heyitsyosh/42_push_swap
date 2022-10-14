/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks_ii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:20:51 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 01:57:31 by myoshika         ###   ########.fr       */
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

static int	coordinate_compression(t_stack	*node, t_save *s)
{
	t_stack	*tmp;
	int		smaller_inputs;

	tmp = *(s->a_head);
	smaller_inputs = 0;
	while (tmp)
	{
		if (tmp->input < node->input)
			smaller_inputs++;
		tmp = tmp->next;
	}
	return (smaller_inputs);
}

void	get_lmis_and_compressed_coordinates(t_save *s)
{
	t_stack	*tmp;

	tmp = *(s->a_head);
	s->min = (*s->a_head)->input;
	s->has_duplicate = false;
	while (tmp)
	{
		tmp->lmis = count_subsequence(tmp, s);
		if (s->has_duplicate)
			break ;
		tmp->cc = coordinate_compression(tmp, s);
		tmp = tmp->next;
	}
}
