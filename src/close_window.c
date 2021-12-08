/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:14 by coder             #+#    #+#             */
/*   Updated: 2021/12/08 18:28:52 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	printf("Au revoir\n");
	exit(0);
	return (0);
}

void	print_error(int signal)
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
	exit(0);
}