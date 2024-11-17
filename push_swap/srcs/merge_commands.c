/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 08:30:05 by myoshika          #+#    #+#             */
/*   Updated: 2024/11/18 07:06:42 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free, NULL
#include "push_swap.h"

static t_type	get_merged_type(t_command *a, t_command *b)
{
	if ((a->type == SA && b->type == SB)
		|| (a->type == SB && b->type == SA))
		return (SS);
	else if ((a->type == RA && b->type == RB)
		|| (a->type == RB && b->type == RA))
		return (RR);
	else if ((a->type == RRA && b->type == RRB)
		|| (a->type == RRB && b->type == RRA))
		return (RRR);
	return (NO_COMMAND);
}

static int	merge(t_command *a, t_command *b, t_type merged_type)
{
	int		merged_count;
	t_type	saved_a_type;
	t_type	saved_b_type;

	merged_count = 0;
	saved_a_type = a->type;
	saved_b_type = b->type;
	while (a->type == saved_a_type && b->type == saved_b_type)
	{
		a->type = merged_type;
		merged_count++;
		a = a->next;
		b = b->next;
	}
	return (merged_count);
}

static t_command	*merge_redundant(t_command *a, t_command *b, bool *reduced)
{
	t_type		merged_type;
	int			merged_count;
	t_command	*b_prev;

	merged_type = get_merged_type(a, b);
	if (merged_type == NO_COMMAND)
		return (b);
	*reduced = true;
	merged_count = merge(a, b, merged_type);
	b_prev = a;
	while (b_prev->next && b_prev->next->type != b->type)
		b_prev = b_prev->next;
	while (merged_count--)
		delete_next_node(b_prev);
	return (b_prev->next);
}

static t_command	*find_next_different_command(t_command *a)
{
	t_command	*b;

	b = a->next;
	while (b)
	{
		if (b->type != a->type)
			return (b);
		b = b->next;
	}
	return (NULL);
}

bool	merge_commands(t_info *i)
{
	t_command	*cmd_a;
	t_command	*cmd_b;
	bool		reduced;

	reduced = false;
	if (!i->commands)
		return (reduced);
	cmd_a = i->commands;
	while (cmd_a)
	{
		cmd_b = find_next_different_command(cmd_a);
		if (!cmd_b)
			break ;
		cmd_a = merge_redundant(cmd_a, cmd_b, &reduced);
	}
	return (reduced);
}
