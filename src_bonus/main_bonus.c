/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:56:47 by coder             #+#    #+#             */
/*   Updated: 2021/12/12 23:39:58 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_global	global;

	global.map = malloc(sizeof(t_map) * 1);
	global.data = malloc(sizeof(t_data) * 1);
	global.map->collectables = 0;
	global.map->players = 0;
	global.map->out = 0;
	global.data->end_game = 0;
	global.map->moves = 0;
	global.data->side = S;
	if (argc != 2)
		print_error(5, &global);
	if (!ft_strnstr(argv[1], ".ber", 50))
		print_error(5, &global);
	count_map(&global, argv[1]);
	global.data->mlx_ptr = mlx_init();
	global.data->mlx_win = mlx_new_window(global.data->mlx_ptr, \
		global.map->columns * SIZE_IMG, \
		global.map->lines * SIZE_IMG, "So_long");
	load_image(&global);
	mlx_hook(global.data->mlx_win, KEY_PRESS, 1L << 0, key_map, &global);
	mlx_hook(global.data->mlx_win, CLICK_X, 0, close_window, &global);
	mlx_loop_hook(global.data->mlx_ptr, put_images, &global);
	mlx_loop(global.data->mlx_ptr);
	return (0);
}
