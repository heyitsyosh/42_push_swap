/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:20:55 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/11 09:02:57 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc, exit, NULL
#include "push_swap.h"
#include "ft_printf.h"

void	append_command(t_info *i, t_type type)
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
	c->type = type;
	c->next = NULL;
}

char	*get_string(t_type type)
{
	if (type == PA)
		return ("pa");
	else if (type == PB)
		return ("pb");
	else if (type == SA)
		return ("sa");
	else if (type == SB)
		return ("sb");
	else if (type == SS)
		return ("ss");
	else if (type == RA)
		return ("ra");
	else if (type == RB)
		return ("rb");
	else if (type == RR)
		return ("rr");
	else if (type == RRA)
		return ("rra");
	else if (type == RRB)
		return ("rrb");
	else if (type == RRR)
		return ("rrr");
	return (NULL);
}

void	print_commands(t_info *i)
{
	t_command	*next;

	reduce_commands(i);
	next = i->commands;
	while (next)
	{
		ft_printf("%s\n", get_string(next->type));
		next = next->next;
	}
}
