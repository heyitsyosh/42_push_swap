/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 06:51:43 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/11 11:01:59 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free
#include "push_swap.h"
#include "libft.h"

static void	delete_next_node(t_command *node)
{
	t_command	*to_delete;

	to_delete = node->next;
	if (!to_delete)
		return ;
	node->next = to_delete->next;
	free(to_delete);
}

static bool	delete_redundant(t_command *prev, t_command *a, t_command *b)
{
	if ((a->type == PA && b->type == PB)
		|| (a->type == PB && b->type == PA)
		|| (a->type == SA && b->type == SA)
		|| (a->type == RA && b->type == RRA)
		|| (a->type == RRA && b->type == RA)
		|| (a->type == RB && b->type == RRB)
		|| (a->type == RRB && b->type == RB)
		|| (a->type == RR && b->type == RRR)
		|| (a->type == RRR && b->type == RR))
	{
		delete_next_node(prev);
		delete_next_node(prev);
		return (true);
	}
	return (false);
}


static t_type get_abbreviation_type(t_command *a, t_command *b) {
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

static t_command *perform_abbreviation(t_command *a, t_command *b, int a_count, int b_count) {
	const t_type a_type = a->type;
	const t_type b_type = b->type;
	t_type abbreviation_type;

	abbreviation_type = get_abbreviation_type(a, b);
	if (abbreviation_type != NO_COMMAND) {
		while (a_count && b_count) {
			a->type = abbreviation_type;
			delete_next_node(a);
			a = a->next;
			a_count--;
			b_count--;
		}
		while (a_count > 0 && b->type == b_type) {
			b->type = a_type;
			b = b->next;
			a_count--;
		}
	}
	else
		while (a_count--)
			a = a->next;
	return (a);
}

int count_consecutive_commands(t_command **command_ptr) {
	int count;
	t_type type;
	t_command *command;

	command = *command_ptr;
	if (command)
		type = command->type;
	count = 0;
	while (command && command->type == type) {
		count++;
		command = command->next;
	}
	*command_ptr = command;
	return (count);
}

static void	replace_redundant(t_command *current)
{
	int			a_count;
	int			b_count;
	t_command	*a;
	t_command	*b;

	while (current) {
		a = current;
		a_count = count_consecutive_commands(&current);
		b = current;
		b_count = count_consecutive_commands(&current);
		if (!a || !b)
			return ;
		current = perform_abbreviation(a, b, a_count, b_count);
	}
}

void	reduce_commands(t_info *i)
{
	t_command	*next;

	if (!i->commands)
		return ;
	next = i->commands;
	while (next && next->next && (next->next)->next)
	{
		delete_redundant(next, next->next, (next->next)->next);
		next = next->next;
	}
	replace_redundant(i->commands);
}
