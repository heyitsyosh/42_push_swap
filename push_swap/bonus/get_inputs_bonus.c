/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:46:16 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/10 21:07:42 by myoshika         ###   ########.fr       */
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

static bool	malloc_a_and_b(int *a, int *b, int argc, char **argv)
{
	if (!ft_strcmp(argv[0], "push_swap"))
		return (false);
	a = (int *)malloc(sizeof(int) * (argc - 1));
	b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!a || !b)
	{
		free(a);
		free(b);
		return (false);
	}
	return (true);
}

bool	make_stack_a_and_b(int *a, int *b, int argc, char **argv)
{
	size_t	i;
	bool	overflow;
	int		a_top;

	if (!malloc_a_and_b(a, b, argc, argv))
		return (false);
	i = 0;
	a_top = argc - 2;
	overflow = false;
	while (a_top - i >= 0)
	{
		a[a_top - i] = atoi_with_overflow_check(argv[i + 1], &overflow);
		if (overflow || !str_is_num(argv[i + 1]))
		{
			free(a);
			free(b);
			return (false);
		}
		i++;
	}
	return (true);
}

char	**get_instructions(void)
{
	char	*line;
	char	*joined_instructions;
	char	**instructions;

	joined_instructions = ft_strdup("");
	while (joined_instructions)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		ft_strjoin_with_free(joined_instructions, line, FREE_FIRST_PARAM);
		free(line);
	}
	instructions = ft_split(joined_instructions, '\n');
	free(joined_instructions);
	return (instructions);
}
