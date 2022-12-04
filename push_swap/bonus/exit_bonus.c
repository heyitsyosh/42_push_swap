/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:25:39 by myoshika          #+#    #+#             */
/*   Updated: 2022/12/05 00:20:41 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	free_double_ptr(char **to_free)
{
	size_t	i;

	i = 0;
	if (to_free)
		while (to_free[i])
			free(to_free[i++]);
	free(to_free);
}

void	free_and_exit(int *a, int *b, char **instructions)
{
	free(a);
	free(b);
	free_double_ptr(instructions);
	ft_printf("Error\n");
	exit(0);
}
