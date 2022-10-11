/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 23:12:15 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/11 02:28:01 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./get_next_line.h"
# include "./ft_printf.h"

typedef struct s_list
{
	struct s_list	*prev;
	int				num;
	struct s_list	*next;
}	t_list;

typedef struct s_save
{
	struct s_list	*top;
	struct s_list	*bottom;
}	t_list;

#endif