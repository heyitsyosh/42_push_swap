/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:25 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 03:31:40 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	str_is_num(char *str)
{
	if (!*str)
		return (false);
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

static bool	malloc_head(t_save *s, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (ft_strcmp(argv[0], "./push_swap"))
		return (false);
	a = make_node(argv[1]);
	if (!a)
	{
		free(a);
		return (false);
	}
	b = NULL;
	s->a_head = &a;
	s->b_head = &b;
	return (true);
}

bool	make_stack_a_and_b(t_save *s, int argc, char **argv)
{
	int		i;
	t_stack	*new;

	if (!malloc_head(s, argv))
		return (false);
	i = 2;
	printf("a[{%p}]\n", *(s->a_head));
	while (i < argc)
	{
		new = make_node(argv[i]);
		printf("[%p, i:%d]", new, i);
		if (!new)
		{
			free_a_and_b(s);
			return (false);
		}
		stack_add_back(new, s->a_head);
		i++;
	}
	return (true);
}
