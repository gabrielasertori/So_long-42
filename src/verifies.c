/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:43:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/08 20:46:40 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		verify_first_and_last(t_map *map);
void	verify_map(t_map *map);

int	count_items(char c, t_map *map)
{
	if (c == 'P')
		map->players++;
	else if (c == 'C')
		map->collectables++;
	else if (c == 'E')
		map->out++;
	else if (c == '1' || c == '0' || c == '\n')
		return(1);
	else
		print_error(3);
	return (1);
}

void	verify_map(t_map *map)
{
	int	lines;
	int	columns;
	int	i;

	columns = 0;
	lines = 1;

	i = verify_first_and_last(map);
	map->columns = i;
	while (lines < map->lines - 2)
	{
		if (map->matrix[lines][0] != '1' || map->matrix[lines][i - 1] != '1')
			print_error(3);
		columns = 0;
		while (map->matrix[lines][columns])
			columns++;
		if (columns != map->columns)
			print_error(3);
		lines++;
	}
}

int	verify_first_and_last(t_map *map)
{
	int	i;
	int	col_size;

	i = 0;
	col_size = ft_strlen(map->matrix[0]);
	while (col_size > 0 && map->matrix[0])
	{
		if (map->matrix[0][i] != '1')
			print_error(3);
		col_size--;
		i++;
	}
	return (i);
}