/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:25 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/12 18:36:51 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	malloc_head(t_save *s, int argc, char **argv)
{
	if (ft_strcmp(argv[0], "push_swap"))
		return (false);
	s->a_head = make_node(argv[1], s);
	s->b_head = (t_stack *)malloc(sizeof(t_stack));
	if (!s->a_head || !s->b_head)
	{
		free(s->a_head);
		free(s->b_head);
		return (false);
	}
	s->b_head->prev = NULL;
	s->a_head->prev = NULL;
	s->b_head->next = NULL;
	return (true);
}

static bool	str_is_num(char *str)
{
	if (!*str)
		return (false);
	while (*str)
	{
		if ('0' > *str || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

t_stack	*make_node(char *arg, t_save *s)
{
	t_stack	*ret;
	bool	overflow;
	bool	is_duplicate;

	overflow = false;
	is_duplicate = false;
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

void	add_node_to_back()
{
	
}

bool	make_stack_a_and_b(t_save *s, int argc, char **argv)
{
	int		i;
	t_stack	*new;

	if (!malloc_head(s, argc, argv))
		return (false);
	i = 1;
	s->last = s->a_head;
	while (i < argc)
	{
		new = make_node(argv[1 + i], s);
		if (!new)
		{
			clear_a_and_b(s);
			return (false);
		}
		add_node_to_back(new, s->last, s);
		s->last = s->a_head->next;
		i++;
	}
	return (true);
}
