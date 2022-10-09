/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:17:30 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/10 07:10:46 by myoshika         ###   ########.fr       */
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
int		atoi_with_overflow_check(const char *str, bool *overflow);

void	sa(int *a, t_sizes *s);
void	sb(int *b, t_sizes *s);
void	ss(int *a, int *b, t_sizes *s);

void	pa(int *a, int *b, t_sizes *s);
void	pb(int *a, int *b, t_sizes *s);

void	ra(int *a, t_sizes *s);
void	rb(int *b, t_sizes *s);
void	rr(int *a, int *b, t_sizes *s);

void	rra(int *a, t_sizes *s);
void	rrb(int *b, t_sizes *s);
void	rrr(int *a, int *b, t_sizes *s);

#endif