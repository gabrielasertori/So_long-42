/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:02:28 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/13 03:51:16 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	move_player(t_global *global, int col, int line, int key);
static int	moves_verify(t_global *global, int col, int line, int key);
static void	check_side(t_global *global, int key);

int	key_map(int key, t_global *global)
{
	int	line;
	int	col;

	line = global->data->pos_line;
	col = global->data->pos_col;
	if (key == ESC || key == QUIT)
		close_window(global);
	else if (key == A || key == ARROW_LEFT)
		col--;
	else if (key == W || key == ARROW_UP)
		line--;
	else if (key == S || key == ARROW_DOWN)
		line++;
	else if (key == D || key == ARROW_RIGHT)
		col++;
	if (global->data->end_game == 0)
		move_player(global, col, line, key);
	return (0);
}

static void	check_side(t_global *global, int key)
{
	if (key == A || key == ARROW_LEFT)
		global->data->side = 97;
	if (key == W || key == ARROW_UP)
		global->data->side = 119;
	if (key == S || key == ARROW_DOWN)
		global->data->side = 115;
	if (key == D || key == ARROW_RIGHT)
		global->data->side = 100;
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
		check_side(global, key);
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
	if (global->map->matrix[line][col] == 'Y')
	{
		global->data->end_game = 1;
		return (-1);
	}
	if (global->map->matrix[line][col] == 'E' && global->map->collectables == 0)
	{
		global->map->matrix[global->data->pos_line] \
		[global->data->pos_col] = '0';
		global->data->end_game = 1;
		return (-1);
	}
	else if (global->map->matrix[line][col] == 'E')
		return (-1);
	if (key != A && key != W && key != S && key != D && key != ARROW_UP
		&& key != ARROW_DOWN && key != ARROW_LEFT && key != ARROW_RIGHT)
		return (-1);
	else
		return (1);
}
