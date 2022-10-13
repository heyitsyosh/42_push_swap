/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:09:58 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 14:31:33 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	adjust_compressed_coordinates(t_save *s)
{
	t_stack	*tmp;

	tmp = s->a_head;
	while (tmp)
	{
		tmp->i += s->min;
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_save	s;

	if (argc <= 1 || !make_stack_a_and_b(&s, argc, argv))
		return (0);
	if (!has_duplicates(&s))
	{
		free_a_and_b(&s);
		return (0);
	}
	adjust_compressed_coordinates(&s);
	get_lmis();
	algorithm();
	return (0);
}
