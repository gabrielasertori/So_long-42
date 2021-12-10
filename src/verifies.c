/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:43:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/10 16:25:59 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		verify_first_and_last(t_global *global);
void	verify_map(t_global *global);

void	verify_map(t_global *global)
{
	int	lines;
	int	columns;
	int	i;

	columns = 0;
	lines = 1;
	i = verify_first_and_last(global);
	global->map->columns = i;
	while (lines < global->map->lines - 2)
	{
		if (global->map->matrix[lines][0] != '1' ||
			global->map->matrix[lines][i - 1] != '1')
			print_error(3, global);
		columns = 0;
		while (global->map->matrix[lines][columns])
			columns++;
		if (columns != global->map->columns)
			print_error(3, global);
		lines++;
	}
}

int	verify_first_and_last(t_global *global)
{
	int	i;
	int	col_size;

	i = 0;
	col_size = ft_strlen(global->map->matrix[0]);
	while (col_size > 0 && global->map->matrix[0])
	{
		if (global->map->matrix[0][i] != '1')
			print_error(3, global);
		col_size--;
		i++;
	}
	return (i);
}
