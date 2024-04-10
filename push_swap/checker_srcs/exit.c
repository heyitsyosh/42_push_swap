/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:25:39 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/10 07:56:34 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //free, exit, size_t
#include "checker.h"
#include "ft_printf.h"

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
