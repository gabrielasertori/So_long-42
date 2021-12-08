/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:10:29 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/08 20:55:59 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FD 256
# define BUFFER_SIZE 1
# include <unistd.h>
# include <stdlib.h>
#include "so_long.h"

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *string);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif
