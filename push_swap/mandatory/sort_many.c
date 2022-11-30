/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:46:18 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/28 16:34:51 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_many(t_info *i)
{
	i->first_divide = true;
	i->b_pivot = get_first_quartile(i->a_head);
	divide(get_median(i->a_head), 0, 1, i);
	combine(i);
}
