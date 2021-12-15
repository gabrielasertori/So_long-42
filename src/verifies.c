/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:43:06 by gcosta-d          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/12/13 02:57:52 by gcosta-d         ###   ########.fr       */
=======
/*   Updated: 2021/12/13 01:20:54 by gcosta-d         ###   ########.fr       */
>>>>>>> 172b16ad2b0c1d4d4490f9aeaf44d84e78c08205
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
<<<<<<< HEAD
	i = global->map->columns;
	verify_first(global);
=======
	i = verify_first_and_last(global);
	global->map->columns = i;
>>>>>>> 172b16ad2b0c1d4d4490f9aeaf44d84e78c08205
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
