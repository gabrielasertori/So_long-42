/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:10 by coder             #+#    #+#             */
/*   Updated: 2021/12/12 23:56:24 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_player(t_global *global, int col, int line, int key);
static int	moves_verify(t_global *global, int col, int line, int key);

int	key_map(int key, t_global *global)
{
	int	line;
	int	col;

	line = global->data->pos_line;
	col = global->data->pos_col;
	if (key == ESC || key == QUIT)
		close_window(global);
	else if (key == 'a' || key == ARROW_LEFT)
		col--;
	else if (key == 'w' || key == ARROW_UP)
		line--;
	else if (key == 's' || key == ARROW_DOWN)
		line++;
	else if (key == 'd' || key == ARROW_RIGHT)
		col++;
	if (global->data->end_game == 0)
		move_player(global, col, line, key);
	return (0);
}

static void	move_player(t_global *global, int col, int line, int key)
{
	int	validate;
	int	x;
	int	y;

	x = global->data->pos_line;
	y = global->data->pos_col;
	validate = moves_verify(global, col, line, key);
	if (validate == 1)
	{
		global->map->moves++;
		global->map->matrix[x][y] = '0';
		global->map->matrix[line][col] = 'P';
		global->data->pos_line = line;
		global->data->pos_col = col;
		put_images(global);
		printf("moves: %d\n", global->map->moves);
	}
}

static int	moves_verify(t_global *global, int col, int line, int key)
{
	if (global->map->matrix[line][col] == '1')
		return (-1);
	if (global->map->matrix[line][col] == 'C')
		global->map->collectables--;
	if (global->map->matrix[line][col] == 'E' && global->map->collectables == 0)
	{
		global->map->matrix[global->data->pos_line] \
		[global->data->pos_col] = '0';
		global->data->end_game = 1;
		return (-1);
	}
	else if (global->map->matrix[line][col] == 'E')
		return (-1);
	if (key != 'a' && key != 'w' && key != 's' && key != 'd' && key != ARROW_UP
		&& key != ARROW_DOWN && key != ARROW_LEFT && key != ARROW_RIGHT)
		return (-1);
	else
		return (1);
}
