/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/17 12:50:02 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	swap_opportunity();

// void	combine(t_save *s)
// {
// 	int	tail_cost;
// 	int	swap_opportunity;

// 	while (s->b_size != 0)
// 	{
// 		swap_opportunity(s);
// 	}
// }

void	sort_many(t_save *s)
{

	s->first_divide = true;
	s->b_pivot = get_first_quartile(s->a_head);
	tmp_print_lis(s);
	tmp_print_booll(s);
	tmp_print(s, NULL);
	printf("[lds:%d | len:%d]\n", s->lis->cc, s->lis->i_s_len);
	printf("[lds:%d]\n", s->lis_end->cc);
	printf("[b_pivot:%d]\n", s->b_pivot);
	fflush(stdout);
	divide(get_median(s->a_head), 0, s);
	//combine(s);
}

//possible optimization
//determine closest 