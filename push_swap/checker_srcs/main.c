/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:25:39 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/10 07:59:40 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //STDIN_FILENO
#include <stdlib.h> //free, size_t, NULL
#include "ft_printf.h"
#include "checker.h"
#include "libft.h"

static bool	do_action(char *instruction, int *a, int *b, t_sizes *s)
{
	if (!ft_strcmp(instruction, "sa"))
		sa(a, s);
	else if (!ft_strcmp(instruction, "sb"))
		sb(b, s);
	else if (!ft_strcmp(instruction, "ss"))
		ss(a, b, s);
	else if (!ft_strcmp(instruction, "pa"))
		pa(a, b, s);
	else if (!ft_strcmp(instruction, "pb"))
		pb(a, b, s);
	else if (*instruction == 'r')
	{
		if (!redirect_to_rotator(instruction, a, b, s))
			return (false);
	}
	else
		return (false);
	return (true);
}

static bool	check_if_a_sorted(int *a, t_sizes *s)
{
	int	i;
	int	prev;

	i = 0;
	prev = a[0];
	while (++i <= s->a_top)
	{
		if (prev < a[i])
			return (false);
		prev = a[i];
	}
	return (true);
}

int	check_if_sorted(int *a, int *b, char **instructions, t_sizes *s)
{
	if (s->b_top != -1 || !check_if_a_sorted(a, s))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(a);
	free(b);
	free_double_ptr(instructions);
	return (0);
}

static bool	has_duplicates(int *a, int a_top)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a_top)
	{
		j = i + 1;
		while (j <= a_top)
		{
			if (a[i] == a[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	size_t	i;
	int		*a;
	int		*b;
	char	**instructions;
	t_sizes	sizes;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	if (!make_stack_a_and_b(&a, &b, argc, argv) || has_duplicates(a, argc - 2))
		free_and_exit(a, b, NULL);
	instructions = get_instructions(a, b);
	i = 0;
	sizes.a_top = argc - 2;
	sizes.b_top = -1;
	while (instructions[i])
	{
		if (!do_action(instructions[i], a, b, &sizes))
			free_and_exit(a, b, instructions);
		i++;
	}
	return (check_if_sorted(a, b, instructions, &sizes));
}
