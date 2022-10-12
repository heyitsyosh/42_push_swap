/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:09:58 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/12 17:33:27 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	malloc_head(t_save *s, int argc, char **argv)
{
	if (!ft_strcmp(argv[0], "push_swap"))
		return (false);
	s->a_head = (t_stack *)malloc(sizeof(t_stack));
	s->b_head = (t_stack *)malloc(sizeof(t_stack));
	if (!s->a_head || !s->b_head)
	{
		free(s->a_head);
		free(s->b_head);
		return (false);
	}
	s->b_head->prev = NULL;
	s->a_head->prev = NULL;
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

static bool	add_node(t_stack *head, t_save *s, char *arg)
{
	int		j;
	bool	overflow;

	j = 0;
	overflow = false;
	s->a_head-> = atoi_with_overflow_check(arg, &overflow);
	if (overflow || !str_is_num(arg))
		return (false);
}

bool	make_stack_a_and_b(t_save *s, int argc, char **argv)
{
	int		i;
	t_stack	*new;

	if (!malloc_head(s, argc, argv))
		return (false);
	i = 0;
	while (i < argc)
	{
		new = make_node()
		{
			free(s->a_head);
			free(s->b_head);
			return (false);
		}
		add_node_to_back(s->a_head, s, argv[1 + i])
		s->a_head = 
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_save	s;

	if (argc <= 1)
		return (0);
	// s.a_top = argc - 2;
	// s.b_top = -1;
	make_stack_a_and_b(&s, argc, argv);
}
