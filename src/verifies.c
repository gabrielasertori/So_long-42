/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:43:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/13 02:57:52 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	verify_first(t_global *global);
void	verify_map(t_global *global);

void	verify_map(t_global *global)
{
	int	lines;
	int	columns;
	int	i;

	lines = 1;
	i = global->map->columns;
	verify_first(global);
	while (lines < global->map->lines)
	{
		columns = 0;
		while (global->map->matrix[lines][columns])
			columns++;
		if (columns != global->map->columns)
			print_error(3, global);
		if (global->map->matrix[lines][0] != '1' ||
			global->map->matrix[lines][i - 1] != '1')
			print_error(3, global);
		lines++;
	}
}

static void	verify_first(t_global *global)
{
	int	i;
	int	col_size;

	i = 0;
	col_size = ft_strlen(global->map->matrix[0]);
	while (col_size > 0)
	{
		if (global->map->matrix[0][i] != '1')
			print_error(3, global);
		col_size--;
		i++;
	}
}
