/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:52:51 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/08 02:36:26 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_size(char *argv, t_map *map);
static int	count_items(char *argv, t_map *map);
static void	start(char *buffer, int fd);

int	count_map(t_map *map, char argv[])
{
	count_size(argv, map);
	if (map->lines < 3)
		print_error(3);
	count_items(argv, map);
	if (map->collectables < 1 || map->players < 1 || map->out < 1)
		print_error(4);
	return (map->lines);
}

static int	count_size(char *argv, t_map *map)
{
	int		fd;
	int		bytes_read;
	char	*read_buffer;

	map->lines = 1;
	map->columns = 0;
	bytes_read = 1;
	fd = open(argv, O_RDONLY);
	read_buffer = malloc(sizeof(char*) * BUFFER_SIZE + 1);
	start(read_buffer, fd);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		map->columns++;
		if (*read_buffer == '\n')
		{
			map->lines++;
			map->columns = 0;
		}
	}
	free(read_buffer);
	close(fd);
	return (1);
}

static int	count_items(char *argv, t_map *map)
{
	int		fd;
	int		bytes_read;
	char	*read_buffer;

	map->collectables = 0;
	map->players = 0;
	map->out = 0;
	bytes_read = 1;
	fd = open(argv, O_RDONLY);
	read_buffer = malloc(sizeof(char*) * BUFFER_SIZE + 1);
	start(read_buffer, fd);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (*read_buffer == 'P')
			map->players++;
		else if (*read_buffer == 'C')
			map->collectables++;
		else if (*read_buffer == 'E')
			map->out++;
	}
	free(read_buffer);
	close(fd);
	return (1);
}

static void	start(char *buffer, int fd)
{
	if (!buffer)
		print_error(0);
	if (fd == -1)
		print_error(1);
}

/*
static void	finish(t_map *map, int fd, char *buffer)
{
	if (map->lines < 3)
		print_error(3);
	if (map->collectables < 1 || map->players < 1 || map->out < 1)
		print_error(4);
	free(buffer);
	close(fd);
}
*/

