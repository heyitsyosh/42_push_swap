/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/16 21:11:47 by myoshika         ###   ########.fr       */
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
	// tmp_print_lis(s);
	// tmp_print_bool(s);
	// tmp_print(s, NULL);
	// printf("[b pivot:%d]\n", find_median(s->a_head, s->a_size, s));
	// printf("[lds:%d | len:%d]\n", s->lis->cc, s->lis->i_s_len);
	// printf("[lds:%d]\n", s->lis_end->cc);
	// fflush(stdout);
	s->first_divide = true;
	divide(find_median(s->a_head, s->a_size, s), 0, s);
	//combine(s);
}
