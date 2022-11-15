/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_combo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:03 by myoshika          #+#    #+#             */
/*   Updated: 2022/11/15 05:01:50 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ss_if_optimal(t_save *s)
{
	if (s->a_size < 2 || s->b_size < 2)
		return (false);
	if (s->a_head->cc < (s->a_head->next)->cc)
		return (false);
	if (s->b_head->cc > (s->b_head->next)->cc)
		return (false);
	ss(s, SS);
	return (true);
}

bool	rr_if_optimal(int original_command, int x, t_save *s)
{
	if (s->a_size < 2 || s->b_size < 2)
		return (false);
	if (original_command == RA)
	{
		if (s->b_head->cc > x)
			return (false);
	}
	else
		if (s->a_head->cc < x)
			return (false);
	rr(s, RR);
	return (true);
}
