/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:18:48 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/17 09:23:13 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_coordinate(t_stack *node, t_stack *head)
{
	t_stack	*next;
	int		smaller_inputs;

	if (node->part_of_lis)
		return (-1);
	next = head;
	smaller_inputs = 0;
	while (next)
	{
		if (next->input < node->input && !next->part_of_lis)
			smaller_inputs++;
		next = next->next;
	}
	return (smaller_inputs);
}

static int	no_lis_coordinate_compression(t_stack *head)
{
	t_stack	*next;
	int		no_lis_stack_size;

	next = head;
	no_lis_stack_size = 0;
	while (next)
	{
		next->no_lis_cc = get_coordinate(next, head);
		if (next->no_lis_cc != -1)
			no_lis_stack_size++;
		next = next->next;
	}
	return (no_lis_stack_size);
}

int	get_median(t_stack *head, int stack_size, t_save *s)
{
	t_stack	*next;
	int		no_lis_stack_size;

	next = head;
	no_lis_stack_size = no_lis_coordinate_compression(head);
	while (next)
	{
		if (next->no_lis_cc == no_lis_stack_size / 2)
			break ;
		next = next->next;
	}
	return (next->cc);
}

int	get_first_quartile(t_stack *head)
{
	t_stack	*next;
	int		no_lis_stack_size;
	float	first_quartile;

	next = head;
	no_lis_stack_size = no_lis_coordinate_compression(head);
	first_quartile = (float)no_lis_stack_size * 0.25;
	first_quartile = (int)first_quartile;
	while (next)
	{
		if (next->no_lis_cc == first_quartile)
			break ;
		next = next->next;
	}
	return (next->cc);
}
