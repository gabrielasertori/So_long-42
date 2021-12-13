/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:02:50 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/13 00:53:08 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_global *global)
{
	free_images(global);
	mlx_clear_window(global->data->mlx_ptr, global->data->mlx_win);
	mlx_destroy_window(global->data->mlx_ptr, global->data->mlx_win);
	mlx_destroy_display(global->data->mlx_ptr);
	mlx_loop_end(global->data->mlx_ptr);
	free(global->data->mlx_ptr);
	free_matrix(global);
	free(global->data);
	free(global->map);
	printf("*.HAPPY XMAS.*\n");
	exit(0);
	return (0);
}

void	print_error(int signal, t_global *global)
{
	if (signal == 0)
		printf("Malloc fail\n");
	if (signal == 1)
		printf("FD returned -1\n");
	if (signal == 3)
		printf("Error\nInvalid map\n");
	if (signal == 4)
		printf("Error\nNot enough items\n");
	if (signal == 5)
		printf("Error\nNot a ber file\n");
	if (global->map->matrix)
		free_matrix(global);
	if (global->map)
		free(global->map);
	if (global->data)
		free(global->data);
	exit(0);
}

void	free_matrix(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->map->lines)
	{
		free(global->map->matrix[i]);
		i++;
	}
	free(global->map->matrix);
}

void	free_images(t_global *global)
{
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_player_front);
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_player_back);
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_player_left);
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_player_right);
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_path);
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_wall);
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_colect);
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_exit_block);
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_exit_open);
}
