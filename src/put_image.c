/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:59:59 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/10 16:45:11 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_map(t_global *global, int line, int col);
static void	put_player(t_global *global, int line, int col);
static void	put_collectables(t_global *global, int line, int col);
static void	put_exit(t_global *global, int line, int col);

int	put_images(t_global *global)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (global->map->matrix[line])
	{
		col = 0;
		while (global->map->matrix[line][col])
		{
			if (global->map->matrix[line][col] == '1')
				put_map(global, line, col);
			else if (global->map->matrix[line][col] == 'C')
				put_collectables(global, line, col);
			else if (global->map->matrix[line][col] == 'E')
				put_exit(global, line, col);
			else if (global->map->matrix[line][col] == '0')
				put_map(global, line, col);
			else if (global->map->matrix[line][col] == 'P')
				put_player(global, line, col);
			col++;
		}
		line++;
	}
	return (1);
}

static void	put_map(t_global *global, int line, int col)
{
	if (global->map->matrix[line][col] == '1')
	{
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_wall, col * SIZE_IMG, line * SIZE_IMG);
	}
	else
	{
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_path, col * SIZE_IMG, line * SIZE_IMG);
	}
}

static void	put_player(t_global *global, int line, int col)
{
	mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
	global->data->img_player_front, col * SIZE_IMG, \
	line * SIZE_IMG);
}

static void	put_collectables(t_global *global, int line, int col)
{
	mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
	global->data->img_colect, col * SIZE_IMG, line * SIZE_IMG);
}

static void	put_exit(t_global *global, int line, int col)
{
	if (global->map->collectables == 0)
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_exit_open, col * SIZE_IMG, line * SIZE_IMG);
	else
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_exit_block, col * SIZE_IMG, line * SIZE_IMG);
}
