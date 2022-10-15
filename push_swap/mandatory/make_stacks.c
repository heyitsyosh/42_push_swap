/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:25 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 23:20:57 by myoshika         ###   ########.fr       */
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
		ret->tail = false;
		ret->next = NULL;
		if (overflow || !str_is_num(arg))
		{
			free(ret);
			return (NULL);
		}
	}
	return (ret);
}

static bool	malloc_head(t_save *s, int argc, char **argv)
{
	s->b_head = NULL;
	s->b_head = NULL;
	if (argc > 1)
	{
		s->a_head = make_node(argv[1]);
		if (!s->a_head)
			return (false);
	}
	return (true);
}

void	make_circular(t_save *s, int argc)
{
	t_stack	*last;

	if (!s->a_head)
		return ;
	if (argc == 2)
	{
		s->a_head->next = s->a_head;
		s->a_head->prev = s->a_head;
	}
	else
	{
		last = stack_last(s->a_head);
		last->next = s->a_head;
		s->a_head->prev = last;
		last->tail = true;
	}
}

bool	make_stack_a_and_b(t_save *s, int argc, char **argv)
{
	int		i;
	t_stack	*new;

	if (!malloc_head(s, argc, argv))
		return (false);
	i = 2;
	while (i < argc)
	{
		new = make_node(argv[i]);
		if (!new)
		{
			free_a_and_b(s);
			return (false);
		}
		stack_add_back(new, &(s->a_head));
		i++;
	}
	return (true);
}
