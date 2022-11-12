/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:20:55 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/12 13:29:54 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_command(t_save *s, int command)
{
	t_command	*c;

	//printf("%s\n", command_to_add);
	c = (t_command *)malloc(sizeof(t_command));
	if (!c)
	{
		printf("Error\n");
		free_nodes(s);
		exit (1);
	}
	if (s->commands == NULL)
		s->commands = c;
	if (s->last_command)
		s->last_command->next = c;
	s->last_command = c;
	c->command = command;
	c->next = NULL;
}

static char	*get_string(int command)
{
	if (command == PA)
		return ("pa");
	else if (command == PB)
		return ("pb");
	else if (command == SA)
		return ("sa");
	else if (command == SB)
		return ("sb");
	else if (command == SS)
		return ("ss");
	else if (command == RA)
		return ("ra");
	else if (command == RB)
		return ("rb");
	else if (command == RR)
		return ("rr");
	else if (command == RRA)
		return ("rra");
	else if (command == RRB)
		return ("rrb");
	else if (command == RRR)
		return ("rrr");
	return (NULL);
}

void	print_commands(t_save *s)
{
	t_command	*next;

	next = s->commands;
	while (1)
	{
		if (!reduce_commands(s))
			break ;
	}
	while (next)
	{
		ft_printf("%s\n", get_string(next->command));
		next = next->next;
	}
}
