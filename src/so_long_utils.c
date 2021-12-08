/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:04:57 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/08 18:13:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	str_in_array(const char *s, char delimiter);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	arr = (char **) malloc((str_in_array(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	a = -1;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s)
			{
				s++;
				j++;
			}
			arr[++a] = (char *) malloc((j + 1) * sizeof(char));
			ft_strlcpy(arr[a], s - j, j + 1);
		}
	}
	return (arr);
}

static int	str_in_array(const char *s, char delimiter)
{
	unsigned int	qnt;

	qnt = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			qnt++;
		}
	}
	return (qnt);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	j;

	src_len = ft_strlen(src);
	j = 0;
	if (size != 0)
	{
		while (j < size - 1 && j != src_len)
		{
			dest[j] = src[j];
			j++;
		}
		dest[j] = 0;
	}
	return (src_len);
}