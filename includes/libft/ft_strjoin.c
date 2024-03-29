/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:03:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/12 23:47:14 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Strjoin concatenate two string in one and return a pointer
 * to the new string.
 */

char	*ft_strjoin(char *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s1_len;
	unsigned int	s2_len;
	char			*s3;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = ft_calloc(s1_len + s2_len + 1, 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		s3[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (s3);
}
