/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 21:38:24 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_save *s)
{
	t_stack *tmp = s->a_head;
	//pa(s);

	while (tmp)
	{
		printf("[%p]", tmp);
		printf("[%d, %d, %d]\n", tmp->input, tmp->cc, tmp->lmis);
		tmp = tmp->next;
	}
	printf("%p\n", s->a_head);
	pb(s);
	//sa(s, SA);
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
