/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:18:48 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/25 03:35:25 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_coordinate(t_stack *node, t_stack *tmp)
{
	int		smaller_inputs;

	if (node->part_of_lis)
		return (-1);
	smaller_inputs = 0;
	while (tmp)
	{
		if (tmp->input < node->input && !tmp->part_of_lis)
			smaller_inputs++;
		tmp = tmp->next;
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

int	get_median(t_stack *head)
{
	int		no_lis_stack_size;

	no_lis_stack_size = no_lis_coordinate_compression(head);
	while (head)
	{
		if (head->no_lis_cc == no_lis_stack_size / 2)
			break ;
		head = head->next;
	}
	return (head->cc);
}

int	get_first_quartile(t_stack *head)
{
	int		no_lis_stack_size;
	float	first_quartile;

	no_lis_stack_size = no_lis_coordinate_compression(head);
	first_quartile = (float)no_lis_stack_size * 0.25;
	first_quartile = (int)first_quartile;
	while (head)
	{
		if (head->no_lis_cc == first_quartile)
			break ;
		head = head->next;
	}
	return (head->cc);
}
