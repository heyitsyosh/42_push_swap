/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:12:15 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/12 17:36:02 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./get_next_line.h"
# include "./ft_printf.h"

struct push_swap
{
	/* data */
};

typedef struct s_stack
{
	struct s_stack	*prev;
	int				input;
	int				i;
	struct s_stack	*next;
}	t_stack;

typedef struct s_save
{
	t_stack	*a_head;
	t_stack	*b_head;
	// int				a_top;
	// int				b_top;
	t_stack	*lmis_i;
	t_stack	*lmis_ii;
	t_stack	*lmis_iii;
	t_stack	*lmis_iv;
}	t_save;

#endif