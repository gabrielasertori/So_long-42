/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:52:51 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/08 20:57:08 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_size(char *argv, t_map *map);
static void	mallocate_map(t_map *map, char *argv, int fd);
static void	start(char *buffer, int fd);

int	count_map(t_map *map, char argv[])
{
	int	fd;

	map->collectables = 0;
	map->players = 0;
	map->out = 0;
	count_size(argv, map);
	if (map->collectables < 1 || map->players < 1 || map->out < 1)
		print_error(4);
	fd = open(argv, O_RDONLY);
	mallocate_map(map, argv, fd);
	if (map->lines == map->columns)
		print_error(3);
	close(fd);
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
		count_items(*read_buffer, map);
		if (*read_buffer == '\n')
		{
			map->lines++;
			map->columns = 0;
		}
	}
	map->columns--;
	free(read_buffer);
	close(fd);
	return (1);
}

static void	mallocate_map(t_map *map, char *argv, int fd)
{
	char	*read_buffer;
	char	*string;
	int		bytes_read;

	bytes_read = 1;
	string = ft_strdup("");
	read_buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	start(read_buffer, fd);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		string = ft_strjoin(string, read_buffer);
	}
	map->matrix = ft_split(string, '\n');
	verify_map(map);
	//free(string);
	free(read_buffer);
}

static void	start(char *buffer, int fd)
{
	if (!buffer)
		print_error(0);
	else if (fd == -1)
		print_error(1);
}
