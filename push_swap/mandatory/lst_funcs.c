/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:34:42 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/13 14:31:41 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_node_to_back()
{
	
}

void	free_a_and_b(t_save *s)
{
	while (s->a_head)
	{
		free(s->a_head);
		s->a_head = s->a_head->next;
	}
	while (s->b_head)
	{
		free(s->b_head);
		s->b_head = s->b_head->next;
	}
}
