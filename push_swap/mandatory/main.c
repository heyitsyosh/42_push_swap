/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:09:58 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 16:20:08 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_save	s;

	if (argc <= 1 || !make_stack_a_and_b(&s, argc, argv))
	{
		printf("ERROR\n");
		return (0);
	}
	get_lmis(&s);
	if (!s.has_duplicates)
	{
		free_a_and_b(&s);
		printf("Error\n");
		return (0);
	}
	adjust_compressed_coordinates(&s);

	t_stack *tmp = s.a_head;
	while (tmp)
	{
		printf("[%d, %d, %d]", tmp->input, tmp->i, tmp->lmis);
		tmp = tmp->next;
	}
	//algorithm();
	free_a_and_b(&s);
	return (0);
}
