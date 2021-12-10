/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:10 by coder             #+#    #+#             */
/*   Updated: 2021/12/10 15:55:34 by gcosta-d         ###   ########.fr       */
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
	printf("col: %d\n line: %d\n", col, line);
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
	printf("x: %d\ny: %d\n\n\n\n", x, y);
	validate = moves_verify(global, col, line, key);
	printf("x: %d\ny: %d\nvalidate: %d\n\n\n\n", x, y, validate);
	if (validate == 1)
	{
		global->map->matrix[x][y] = '0';
		global->map->matrix[line][col] = 'P';
		global->data->pos_line = line;
		global->data->pos_col = col;
	}
	for(int i = 0; global->map->matrix[i]; i++)
		printf("%s\n", global->map->matrix[i]);
	put_images(global);
}

static int	moves_verify(t_global *global, int col, int line, int key)
{
	if (global->map->matrix[line][col] == '1')
	{
		printf("To no 1\n");
		return (-1);
	}
	if (global->map->matrix[line][col] == 'C')
		global->map->collectables--;
	if (global->map->matrix[line][col] == 'E' && global->map->collectables == 0)
	{
		global->map->matrix[global->data->pos_line][global->data->pos_col] = '0';
		global->data->end_game = 1;
		return (-1);
	}
	else if (global->map->matrix[line][col] == 'E')
	{
		printf("To no E\n");
		return (-1);
	}
	if (key != 'a' && key != 'w' && key != 's' && key != 'd' && key != ARROW_UP
			&& key != ARROW_DOWN && key != ARROW_LEFT && key != ARROW_RIGHT)
	{
		printf("To no key\n");
		return (-1);
	}
	else
		return (1);
}

// Key == 'a' é posição atual menos um na coluna
// Key == 'w' é posição atual menos um na linha
// Key == 's' é posição atual mais um na linha
// Key == 'd' é posição atual mais um na coluna