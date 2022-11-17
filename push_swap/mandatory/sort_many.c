/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/17 23:10:38 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_many(t_save *s)
{
	s->first_divide = true;
	s->b_pivot = get_first_quartile(s->a_head);
	divide(get_median(s->a_head), 0, 0, s);
	tmp_print_lis(s);
	tmp_print_bool(s);
	//combine(s);
}
