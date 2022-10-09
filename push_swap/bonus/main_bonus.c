/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:25:39 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/10 06:59:28 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	free_and_exit(char **to_free)
{
	size_t	i;

	i = 0;
	if (to_free)
		while (to_free[i])
			free(to_free[i++]);
	free(to_free);
	ft_printf("Error\n");
	exit(0);
}

static bool	do_action(char instruction, int *a, int *b, t_sizes *s)
{
	if (ft_strcmp(instruction, "sa"))
		sa(a, s);
	else if (ft_strcmp(instruction, "sb"))
		sb(b, s);
	else if (ft_strcmp(instruction, "ss"))
		ss(a, b, s);
	else if (ft_strcmp(instruction, "pa"))
		pa(a, b, s);
	else if (ft_strcmp(instruction, "pb"))
		pb(a, b, s);
	else if (ft_strcmp(instruction, "ra"))
		ra(a, s);
	else if (ft_strcmp(instruction, "rb"))
		rb(b, s);
	else if (ft_strcmp(instruction, "rr"))
		rr(a, b, s);
	else if (ft_strcmp(instruction, "rra"))
		rra(a, s);
	else if (ft_strcmp(instruction, "rrb"))
		rrb(b, s);
	else if (ft_strcmp(instruction, "rrr"))
		rrr(a, b, s);
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
	while (++i < s->size_a)
	{
		if (prev > a[i])
			return (false);
		prev = a[i];
	}
	return (true);
}

static int	check_if_sorted(int *a, int *b, t_sizes *s)
{
	if (s->size_b != 0 || !check_if_a_sorted(a, s))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}

int	main(int argc, char **argv)
{
	size_t	i;
	int		*a;
	int		*b;
	char	**instructions;
	t_sizes	sizes;

	if (argc <= 1 || !make_stack_a_and_b(a, b, argc, argv))
		free_and_exit(NULL);
	instructions = get_instructions();
	if (!instructions)
		free_and_exit(NULL);
	i = 0;
	sizes.size_a = argc - 1;
	sizes.size_b = 0;
	while (instructions[i])
	{
		if (do_action(instructions[i], a, b, &sizes))
		{
			free(a);
			free(b);
			free_and_exit(instructions);
		}
		i++;
	}
	return (check_if_sorted(a, b, &sizes));
}
