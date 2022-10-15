/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/16 03:38:25 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_pivot(t_save *s)
{
	(void)s;
}

void	sort_many(t_save *s)
{
	get_pivot(s);

	t_stack *tmp = s->a_head;
	while (tmp)
	{
		printf("[%p]", tmp);
		fflush(stdout);
		printf("[%d, %d, %d]\n", tmp->input, tmp->cc, tmp->lmis);
		fflush(stdout);
		tmp = tmp->next;
	}
}
