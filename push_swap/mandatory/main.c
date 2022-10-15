/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:09:58 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/16 00:08:25 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_save	s;

	if (argc < 1 || !make_stack_a_and_b(&s, argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	get_lmis_and_compressed_coordinates(&s);
	if (s.has_duplicate)
	{
		ft_printf("Error\n");
		free_a_and_b(&s);
		return (0);
	}
	sort(&s);
	free_a_and_b(&s);
	return (0);
}
