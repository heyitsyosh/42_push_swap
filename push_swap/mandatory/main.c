/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:09:58 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/15 17:29:46 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	start_sort(t_save *s)
{
	if (s->sorted)
		return ;
	if (s->argc - 1 < 6)
		sort_few(s->a_size, s);
	else
		sort_many(s);
}

int	main(int argc, char **argv)
{
	t_save	s;

	if (argc < 1 || !make_stack_a_and_b(&s, argc, argv))
	{
		ft_printf("Errror\n");
		return (0);
	}
	get_lis_and_compressed_coordinates(&s);
	if (s.has_duplicate)
		ft_printf("Error\n");
	else
	{
		start_sort(&s);
		print_commands(&s);
	}
	free_nodes(&s);
	return (0);
}
