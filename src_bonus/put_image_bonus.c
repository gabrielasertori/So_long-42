/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:59:59 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/11 17:53:23 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	put_map(t_global *global, int line, int col);
static void	put_player(t_global *global, int line, int col);
static void	put_items(t_global *global, int line, int col);

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
			put_items(global, line, col);
			col++;
		}
		line++;
	}
	return (1);
}

static void	put_items(t_global *global, int line, int col)
{
	if (global->map->matrix[line][col] == '1' ||
		global->map->matrix[line][col] == '0')
		put_map(global, line, col);
	else if (global->map->matrix[line][col] == 'C')
		put_collectables(global, line, col);
	else if (global->map->matrix[line][col] == 'E')
		put_exit(global, line, col);
	else if (global->map->matrix[line][col] == 'Y')
		put_enemy(global, line, col);
	else if (global->map->matrix[line][col] == 'P')
		put_player(global, line, col);
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
	if (global->data->side == A)
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_player_left, col * SIZE_IMG, \
		line * SIZE_IMG);
	else if (global->data->side == W)
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_player_back, col * SIZE_IMG, \
		line * SIZE_IMG);
	else if (global->data->side == D)
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_player_right, col * SIZE_IMG, \
		line * SIZE_IMG);
	else if (global->data->side == S)
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_player_front, col * SIZE_IMG, \
		line * SIZE_IMG);
}
