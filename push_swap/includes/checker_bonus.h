/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:17:30 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/10 06:43:30 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "./get_next_line.h"
# include "./ft_printf.h"

typedef struct s_sizes{
	int	size_a;
	int	size_b;
}	t_sizes;

bool	make_stack_a_and_b(int *a, int *b, int argc, char **argv);
char	**get_instructions(void);

#endif