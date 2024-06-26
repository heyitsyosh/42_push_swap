/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myoshika <myoshika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:49:15 by myoshika          #+#    #+#             */
/*   Updated: 2024/04/10 07:27:29 by myoshika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# elif BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FREE_NONE 0
# define FREE_FIRST_PARAM 1
# define FREE_SECOND_PARAM 2

char	*ft_strjoin_with_free(char *s1, char *s2, int to_free);

char	*get_next_line(int fd);

#endif
