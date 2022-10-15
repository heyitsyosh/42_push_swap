/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/16 00:45:57 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_save *s)
{
	t_stack *tmp = s->a_head;

	// if (!s->a_head)
	// 	return ;
	while (tmp)
	{
		printf("[%p]", tmp);
		printf("[%d, %d, %d]\n", tmp->input, tmp->cc, tmp->lmis);
		tmp = tmp->next;
	}
	tmp = s->a_tail;
	printf("[%d, %d, %d]\n", tmp->input, tmp->cc, tmp->lmis);
	// sa(s, SA);
	// pb(s);
	// pa(s);
	rra(s, RRA);
	tmp = s->a_head;
	while (tmp)
	{
		printf("[%p]", tmp);
		fflush(stdout);
		printf("[%d, %d, %d]\n", tmp->input, tmp->cc, tmp->lmis);
		fflush(stdout);
		tmp = tmp->next;
	}
}
