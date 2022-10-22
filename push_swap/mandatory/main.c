/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:09:58 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/23 06:09:30 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void tmp_print(t_save *s)
{
	t_stack *next;
	next = s->a_head;
	printf("a:");
	while (next)
	{
		printf("[%d]", next->cc);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
	next = s->b_head;
	printf("b:");
	while (next)
	{
		printf("[%d]", next->cc);
		fflush(stdout);
		next = next->next;
	}
	printf("\n");
}

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
		ft_printf("Error\n");
		return (0);
	}
	get_lmis_and_compressed_coordinates(&s);
	if (s.has_duplicate)
		ft_printf("Error\n");
	start_sort(&s);
	free_a_and_b(&s);
	return (0);
}
