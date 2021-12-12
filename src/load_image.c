/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:08:03 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/12 23:43:34 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_image_player(t_global *global);
static void	load_image_misc(t_global *global);

void	load_image(t_global *global)
{
	load_image_player(global);
	load_image_misc(global);
}

static void	load_image_player(t_global *global)
{
	global->data->img_player_front = mlx_xpm_file_to_image(\
		global->data->mlx_ptr, PLAYER_FRONT, &(global->data->img_width), \
		&(global->data->img_height));
	global->data->img_player_back = mlx_xpm_file_to_image(\
		global->data->mlx_ptr, PLAYER_BACK, &(global->data->img_width), \
		&(global->data->img_height));
	global->data->img_player_right = mlx_xpm_file_to_image(\
		global->data->mlx_ptr, PLAYER_RIGHT, &(global->data->img_width), \
		&(global->data->img_height));
	global->data->img_player_left = mlx_xpm_file_to_image(\
		global->data->mlx_ptr, PLAYER_LEFT, &(global->data->img_width), \
		&(global->data->img_height));
}

static void	load_image_misc(t_global *global)
{
	global->data->img_exit_open = mlx_xpm_file_to_image(\
		global->data->mlx_ptr, EXIT_OPEN, &(global->data->img_width), \
		&(global->data->img_height));
	global->data->img_exit_block = mlx_xpm_file_to_image(\
		global->data->mlx_ptr, EXIT_BLOCK, &(global->data->img_width), \
		&(global->data->img_height));
	global->data->img_path = mlx_xpm_file_to_image(\
		global->data->mlx_ptr, PATH, &(global->data->img_width), \
		&(global->data->img_height));
	global->data->img_colect = mlx_xpm_file_to_image(\
		global->data->mlx_ptr, COLECT, &(global->data->img_width), \
		&(global->data->img_height));
	global->data->img_wall = mlx_xpm_file_to_image(\
		global->data->mlx_ptr, WALL, &(global->data->img_width), \
		&(global->data->img_height));
}
