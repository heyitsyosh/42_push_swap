/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_combo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/12 21:18:37 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_combo(t_save *s)
{
	int	distance;

	distance = find_distance_to_cc(s->biggest_of_sorted + 1, s->b_head, s);
	
}
