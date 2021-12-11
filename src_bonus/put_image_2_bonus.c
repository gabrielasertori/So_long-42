/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:45:27 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/11 17:47:47 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_collectables(t_global *global, int line, int col)
{
	mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
	global->data->img_colect, col * SIZE_IMG, line * SIZE_IMG);
}

void	put_exit(t_global *global, int line, int col)
{
	if (global->map->collectables == 0)
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_exit_open, col * SIZE_IMG, line * SIZE_IMG);
	else
		mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
		global->data->img_exit_block, col * SIZE_IMG, line * SIZE_IMG);
}

void	put_enemy(t_global *global, int line, int col)
{
	mlx_put_image_to_window(global->data->mlx_ptr, global->data->mlx_win, \
	global->data->img_enemy_front, col * SIZE_IMG, line * SIZE_IMG);
}
