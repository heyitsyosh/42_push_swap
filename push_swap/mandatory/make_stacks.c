/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:25 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/15 22:18:18 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	str_is_num(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if ('0' > *str || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

static t_stack	*make_node(char *arg)
{
	t_stack	*ret;
	bool	overflow;

	overflow = false;
	ret = (t_stack *)malloc(sizeof(t_stack));
	if (ret)
	{
		ret->input = atoi_with_overflow_check(arg, &overflow);
		ret->next = NULL;
		if (overflow || !str_is_num(arg))
		{
			free(ret);
			return (NULL);
		}
	}
	return (ret);
}

static void	malloc_head(t_save *s, int argc, char **argv)
{
	if (argc > 1)
	{
		s->a_head = make_node(argv[1]);
		s->a_tail = s->a_head;
		s->a_size++;
		if (!s->a_head)
			exit (1);
	}
}

static void	init_struct(t_save	*s)
{
	s->a_head = NULL;
	s->b_head = NULL;
	s->a_size = 0;
	s->b_size = 0;
	s->commands = NULL;
	s->last_command = NULL;
	s->sorted = true;
	s->has_duplicate = false;
}

void	make_stack_a_and_b(t_save *s, int argc, char **argv)
{
	int		i;
	t_stack	*new;

	init_struct(s);
	malloc_head(s, argc, argv);
	s->argc = argc;
	i = 2;
	while (i < argc)
	{
		new = make_node(argv[i]);
		if (!new)
		{
			free_nodes(s);
			exit (1);
		}
		stack_add_back(new, &(s->a_tail));
		s->a_size++;
		i++;
	}
}
