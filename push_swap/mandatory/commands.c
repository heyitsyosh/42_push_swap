/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:20:55 by myoshika          #+#    #+#             */
/*   Updated: 2022/12/04 05:06:33 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_command(t_info *i, int command)
{
	t_command	*c;

	c = (t_command *)malloc(sizeof(t_command));
	if (!c)
	{
		ft_printf("Error\n");
		free_nodes(i);
		exit (1);
	}
	if (i->commands == NULL)
		i->commands = c;
	if (i->last_command)
		i->last_command->next = c;
	i->last_command = c;
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

void	print_commands(t_info *i)
{
	t_command	*next;

	next = i->commands;
	while (1)
	{
		if (!reduce_commands(i))
			break ;
	}
	while (next)
	{
		ft_printf("%s\n", get_string(next->command));
		next = next->next;
	}
}
