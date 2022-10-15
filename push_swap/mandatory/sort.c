/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/16 01:24:47 by myoshika         ###   ########.fr       */
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
	printf("\n");
	// sa(s, SA);
	// pb(s);
	//pb(s);
	pb(s);
	tmp = s->a_head;
	while (tmp)
	{
		printf("[%p]", tmp);
		fflush(stdout);
		printf("[%d, %d, %d]\n", tmp->input, tmp->cc, tmp->lmis);
		fflush(stdout);
		tmp = tmp->next;
	}
	printf("\n");
	pb(s);
	tmp = s->a_head;
	while (tmp)
	{
		printf("[%p]", tmp);
		fflush(stdout);
		printf("[%d, %d, %d]\n", tmp->input, tmp->cc, tmp->lmis);
		fflush(stdout);
		tmp = tmp->next;
	}
	printf("\n");
	// pb(s);
	pb(s);
	//rb(s, RA);
	//sa(s);
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
