/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/15 02:00:33 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_save *s)
{
	t_stack *tmp = *(s->a_head);
	//pa(s);
	while (tmp)
	{
		printf("[%d, %d, %d]\n", tmp->input, tmp->cc, tmp->lmis);
		tmp = tmp->next;
	}
	pb(s);
	tmp = *(s->a_head);
	while (tmp)
	{
		printf("1");
		printf("[%d, %d, %d]", tmp->input, tmp->cc, tmp->lmis);
		tmp = tmp->next;
	}
}
