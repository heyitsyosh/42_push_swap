/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:17:30 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/10 07:27:39 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>

typedef struct s_sizes{
	int		a_top;
	int		b_top;
}	t_sizes;

bool	make_stack_a_and_b(int **a, int **b, int argc, char **argv);
char	**get_instructions(int *a, int *b);
int		atoi_with_overflow_check(const char *str, bool *overflow);

void	free_double_ptr(char **to_free);
void	free_and_exit(int *a, int *b, char **instructions);

void	sa(int *a, t_sizes *s);
void	sb(int *b, t_sizes *s);
void	ss(int *a, int *b, t_sizes *s);

void	pa(int *a, int *b, t_sizes *s);
void	pb(int *a, int *b, t_sizes *s);

bool	redirect_to_rotator(char *instruction, int *a, int *b, t_sizes *s);

#endif
