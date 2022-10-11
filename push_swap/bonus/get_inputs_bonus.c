/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:46:16 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/11 09:23:45 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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

static bool	malloc_a_and_b(int **a, int **b, int argc, char **argv)
{
	if (!ft_strcmp(argv[0], "push_swap"))
		return (false);
	*a = (int *)malloc(sizeof(int) * (argc - 1));
	*b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!*a || !b)
	{
		free(a);
		free(b);
		return (false);
	}
	return (true);
}

bool	make_stack_a_and_b(int **a, int **b, int argc, char **argv)
{
	int		i;
	bool	overflow;
	int		a_top;

	if (!malloc_a_and_b(a, b, argc, argv))
		return (false);
	i = 0;
	a_top = argc - 2;
	overflow = false;
	while (a_top - i >= 0)
	{
		(*a)[a_top - i] = atoi_with_overflow_check(argv[i + 1], &overflow);
		if (overflow || !str_is_num(argv[i + 1]))
		{
			free(*a);
			free(*b);
			return (false);
		}
		i++;
	}
	return (true);
}

char	**get_instructions(void)
{
	char	*line;
	char	*instructions;
	char	**split_instructions;

	instructions = ft_strdup("");
	while (instructions)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		instructions = ft_strjoin_with_free(instructions, line, 1);
		free(line);
	}
	split_instructions = ft_split(instructions, '\n');
	free(instructions);
	if (!split_instructions)
		free_and_exit(NULL);
	return (split_instructions);
}
