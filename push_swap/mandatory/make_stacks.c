/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:50:25 by myoshika          #+#    #+#             */
/*   Updated: 2022/12/04 20:40:46 by myoshika         ###   ########.fr       */
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

static void	malloc_head(t_info *i, int argc, char **argv)
{
	if (argc > 1)
	{
		i->a_head = make_node(argv[1]);
		i->a_tail = i->a_head;
		i->a_size++;
		if (!i->a_head)
		{
			ft_printf("Error\n");
			exit (1);
		}
		i->a_head->prev = NULL;
	}
}

static void	init_struct(t_info	*i)
{
	i->a_head = NULL;
	i->b_head = NULL;
	i->a_size = 0;
	i->b_size = 0;
	i->commands = NULL;
	i->last_command = NULL;
	i->sorted = true;
	i->has_duplicate = false;
}

void	make_stack_a_and_b(t_info *i, int argc, char **argv)
{
	int		j;
	t_stack	*new;

	init_struct(i);
	malloc_head(i, argc, argv);
	i->argc = argc;
	j = 2;
	while (j < argc)
	{
		new = make_node(argv[j]);
		if (!new)
		{
			free_nodes(i);
			ft_printf("Error\n");
			exit (1);
		}
		stack_add_back(new, &(i->a_tail));
		i->a_size++;
		j++;
	}
}
