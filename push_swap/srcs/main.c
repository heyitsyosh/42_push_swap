/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:09:58 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/10 07:35:38 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void	start_sort(t_info *i)
{
	if (i->sorted)
		return ;
	if (i->argc - 1 < 6)
		sort_few(i->a_size, i);
	else
		sort_many(i);
}

int	main(int argc, char **argv)
{
	t_info	i;

	if (argc > 1)
	{
		make_stack_a_and_b(&i, argc, argv);
		get_lis_and_compressed_coordinates(&i);
	}
	else
		return (0);
	if (i.has_duplicate)
		ft_printf("Error\n");
	else
	{
		start_sort(&i);
		print_commands(&i);
	}
	free_nodes(&i);
	return (0);
}
