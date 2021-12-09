/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:14 by coder             #+#    #+#             */
/*   Updated: 2021/12/09 21:07:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_global *global)
{
	mlx_destroy_image(global->data->mlx_ptr, global->data->img_player_front);
	mlx_clear_window(global->data->mlx_ptr, global->data->mlx_win);
	mlx_destroy_window(global->data->mlx_ptr, global->data->mlx_win);
	mlx_destroy_display(global->data->mlx_ptr);
	mlx_loop_end(global->data->mlx_ptr);
	free(global->data->mlx_ptr);
	free_matrix(global);
	free(global->data);
	free(global->map);
	printf("Au revoir\n");
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
		printf("Invalid map\n");
	if (signal == 4)
		printf("Not enough items\n");
	if (signal == 5)
		printf("Error\n");
	if (global->map->matrix)
		free_matrix(global);
	exit(0);
}

void	free_matrix(t_global *global)
{
	int	i;

	i = 0;
	while(i < global->map->lines)
	{
		free(global->map->matrix[i]);
		i++;
	}
	free(global->map->matrix);
}