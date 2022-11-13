/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_combo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/13 12:46:03 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_combo(t_save *s)
{
	int	distance;

	distance = find_distance_to_cc(s->smallest_of_sorted - 1, s->b_head);
	if (distance > s->b_size / 2)
		while (s->b_head->cc != s->smallest_of_sorted - 1)
			rrb(s, RRA);
	else
		while (s->b_head->cc != s->smallest_of_sorted - 1)
			rb(s, RA);
}
