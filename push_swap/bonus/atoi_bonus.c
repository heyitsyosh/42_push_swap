/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 05:29:25 by myoshika          #+#    #+#             */
/*   Updated: 2022/10/10 05:39:50 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static int	is_whitespace(char c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

static int	make_l(const char *str, size_t i, int sign, bool *overflow)
{
	long	num;

	num = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (sign == 1 && ((num > LONG_MAX / 10)
				|| (num == LONG_MAX / 10 && str[i] - '0' > LONG_MAX % 10)))
			*overflow = true;
		else if (sign == -1 && ((num < LONG_MIN / 10)
				|| (num == LONG_MIN / 10 && str[i] - '0' > LONG_MIN % 10 * -1)))
			*overflow = true;
		if (*overflow)
			break ;
		num = (num * 10) + sign * (str[i] - '0');
		i++;
	}
	return ((int)num);
}

int	atoi_with_overflow_check(const char *str, bool *overflow)
{
	size_t	i;
	int		sign;

	sign = 1;
	i = 0;
	while (is_whitespace(*(str + i)))
		i++;
	if ((*(str + i) == '+' || *(str + i) == '-') && *(str + i))
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	return (make_l(str, i, sign, overflow));
}
