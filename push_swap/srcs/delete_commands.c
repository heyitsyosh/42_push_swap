/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 06:51:43 by myoshika          #+#    #+#             */
/*   Updated: 2024/11/18 06:51:57 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free
#include "push_swap.h"
#include "libft.h"

void	delete_next_node(t_command *node)
{
	t_command	*to_delete;

	to_delete = node->next;
	if (!to_delete)
		return ;
	node->next = to_delete->next;
	free(to_delete);
}

static bool	cancel_out_commands(t_command *prev, t_command *a, t_command *b)
{
	if ((a->type == PA && b->type == PB)
		|| (a->type == PB && b->type == PA)
		|| (a->type == SA && b->type == SA)
		|| (a->type == SB && b->type == SB)
		|| (a->type == RA && b->type == RRA)
		|| (a->type == RRA && b->type == RA)
		|| (a->type == RB && b->type == RRB)
		|| (a->type == RRB && b->type == RB)
		|| (a->type == RR && b->type == RR)
		|| (a->type == RRR && b->type == RRR))
	{
		delete_next_node(prev);
		delete_next_node(prev);
		return (true);
	}
	return (false);
}

bool	delete_commands(t_info *i)
{
	t_command	*next;
	bool		reduced;

	reduced = false;
	if (!i->commands)
		return (reduced);
	next = i->commands;
	while (next && next->next && (next->next)->next)
	{
		if (cancel_out_commands(next, next->next, (next->next)->next))
			reduced = true;
		next = next->next;
	}
	return (reduced);
}
