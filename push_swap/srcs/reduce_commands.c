/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 06:51:43 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/11 11:13:29 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free
#include "push_swap.h"
#include "libft.h"

static void	delete_next_node(t_command	*node)
{
	t_command	*to_delete;

	to_delete = node->next;
	if (!to_delete)
		return ;
	node->next = to_delete->next;
	free(to_delete);
}

static bool	delete_unecessary(t_command	*prev, t_command *a, t_command *b)
{
	if ((a->type == PA && b->type == PB)
		|| (a->type == PB && b->type == PA)
		|| (a->type == SA && b->type == SA)
		|| (a->type == RA && b->type == RRA)
		|| (a->type == RRA && b->type == RA)
		|| (a->type == RB && b->type == RRB)
		|| (a->type == RRB && b->type == RB)
		|| (a->type == RRR && b->type == RRR))
	{
		delete_next_node(prev);
		delete_next_node(prev);
		return (true);
	}
	return (false);
}

static bool	replace_unecessary(t_command *a, t_command *b)
{
	if (!b)
		return (false);
	else if ((a->type == SA && b->type == SB)
		|| (a->type == SB && b->type == SA))
		a->type = SS;
	else if ((a->type == RA && b->type == RB)
		|| (a->type == RB && b->type == RA))
		a->type = RR;
	else if ((a->type == RRA && b->type == RRB)
		|| (a->type == RRB && b->type == RRA))
		a->type = RRR;
	else
		return (false);
	delete_next_node(a);
	return (true);
}

bool	reduce_commands(t_info *i)
{
	t_command	*next;
	bool		reduced;

	reduced = false;
	if (!i->commands)
		return (reduced);
	next = i->commands;
	while (next && next->next && (next->next)->next)
	{
		if (delete_unecessary(next, next->next, (next->next)->next))
			reduced = true;
		if (replace_unecessary(next, next->next))
			reduced = true;
		next = next->next;
	}
	return (reduced);
}
