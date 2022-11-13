/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 06:51:43 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/13 14:18:26 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	delete_next_node(t_command	*prev)
{
	t_command	*new_next;

	new_next = (prev->next)->next;
	free(prev->next);
	prev->next = new_next;
}

static bool	delete_unecessary(t_command	*prev, t_command *a, t_command *b)
{
	if ((a->command == PA && b->command == PB)
		|| (a->command == PB && b->command == PA)
		|| (a->command == SA && b->command == SA)
		|| (a->command == RA && b->command == RRA)
		|| (a->command == RRA && b->command == RA)
		|| (a->command == RB && b->command == RRB)
		|| (a->command == RRB && b->command == RB)
		|| (a->command == RRR && b->command == RRR))
	{
		delete_next_node(prev);
		delete_next_node(a);
		return (true);
	}
	return (false);
}

static bool	replace_unecessary(t_command *a, t_command *b)
{
	if (!b)
		return (false);
	else if ((a->command == SA && b->command == SB)
		|| (a->command == SB && b->command == SA))
		a->command = SS;
	else if ((a->command == RA && b->command == RB)
		|| (a->command == RB && b->command == RA))
		a->command = RR;
	else if ((a->command == RRA && b->command == RRB)
		|| (a->command == RRB && b->command == RRA))
		a->command = RRR;
	else
		return (false);
	delete_next_node(a);
	return (true);
}

bool	reduce_commands(t_save *s)
{
	t_command	*next;
	bool		reduced;

	reduced = false;
	if (!s->commands)
		return (reduced);
	next = s->commands;
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
