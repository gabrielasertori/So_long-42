/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:52:51 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/13 03:30:43 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_size(char *argv, t_global *global);
static int	count_items(char c, t_global *global);
static void	mallocate_map(t_global *global, int fd);
static void	start(char *buffer, int fd, t_global *global);

int	count_map(t_global *global, char argv[])
{
	int	fd;

	count_size(argv, global);
	if (global->map->collectables < 1 || global->map->players < 1
		|| global->map->out < 1)
		print_error(4, global);
	fd = open(argv, O_RDONLY);
	mallocate_map(global, fd);
	if (global->map->lines == global->map->columns)
		print_error(3, global);
	close(fd);
	return (global->map->lines);
}

static int	count_size(char *argv, t_global *global)
{
	int		fd;
	int		bytes_read;
	char	*read_buffer;

	global->map->lines = 1;
	global->map->columns = 0;
	bytes_read = 1;
	fd = open(argv, O_RDONLY);
	read_buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	start(read_buffer, fd, global);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		global->map->columns++;
		count_items(*read_buffer, global);
		if (*read_buffer == '\n')
		{
			global->map->lines++;
			global->map->columns = 0;
		}
	}
	global->map->columns--;
	free(read_buffer);
	close(fd);
	return (1);
}

static int	count_items(char c, t_global *global)
{
	if (c == 'P')
	{
		global->data->pos_col = global->map->columns - 1;
		global->data->pos_line = global->map->lines - 1;
		global->map->players++;
	}
	else if (c == 'C')
		global->map->collectables++;
	else if (c == 'E')
		global->map->out++;
	else if (c == '1' || c == '0' || c == '\n')
		return (1);
	else
		print_error(3, global);
	return (1);
}

static void	mallocate_map(t_global *global, int fd)
{
	char	*read_buffer;
	char	*string;
	int		bytes_read;

	bytes_read = 1;
	string = ft_strdup("");
	read_buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	*(read_buffer + 1) = '\0';
	start(read_buffer, fd, global);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		string = ft_strjoin(string, read_buffer);
	}
	global->map->matrix = ft_split(string, '\n');
	free(string);
	free(read_buffer);
	verify_map(global);
}

static void	start(char *buffer, int fd, t_global *global)
{
	if (!buffer)
		print_error(0, global);
	else if (fd == -1)
		print_error(1, global);
}
