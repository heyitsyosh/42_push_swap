/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:09:58 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 19:47:51 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_save	s;

	if (argc <= 1 || !make_stack_a_and_b(&s, argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	get_lmis_and_compressed_coordinates(&s);

	t_stack *tmp = s.a_head;
	while (tmp)
	{
		printf("[%d, %d]", tmp->input, tmp->lmis);
		tmp = tmp->next;
	}

	if (!s.has_duplicates)
	{
		free_a_and_b(&s);
		ft_printf("Error\n");
		return (0);
	}
	//algorithm();
	free_a_and_b(&s);
	return (0);
}
