/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:52:51 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/07 20:43:47 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	map_width(int fd, char *buffer);

int	count_map(t_map *map, char argv[])
{
	int		lines;
	int		columns;
	int		bytes_read;
	char	*read_buffer;
	int		fd;

	lines = 0;
	columns = 0;
	bytes_read = 0;
	map->lines = 0;
	map->columns = 0;
	map->collectables = 0;
	map->players = 0;
	map->out = 0;
	read_buffer = malloc(sizeof(char*) * BUFFER_SIZE + 1);
	if (!read_buffer)
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	map_width(fd, read_buffer);

	return (lines);
}

/*
VERIFICAÇÕES:
Verificar se é a primeira ou última linha
	Verificar se a linha está totalmente preenchida com 1
Verificar se é linha do meio.
	Verificar se a linha começa e termina com 1.

*/
static int	map_width(int fd, char *buffer)
{
	int	columns;
	int	bytes_read;

	columns = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (*buffer != '\n')
	{
		columns++;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	printf("COLUNAS %d\n", columns);
	return (columns);
}

/*
bytes_read = read(fd, read_buffer, BUFFER_SIZE);
	while (*read_buffer == '1')
	{
		map->columns++;
		read(fd, read_buffer, BUFFER_SIZE);
	}
	if (*read_buffer == '\n')
		map->lines++;
	else
		printf("Não é um mapa válido\n");

	printf("Colunas %d\n", map->columns);
	printf("Linhas %d\n", map->lines);

	while (*read_buffer == '\n' || *read_buffer == '1' || *read_buffer == '0' || *read_buffer == 'P' || *read_buffer == 'C')
	{
		if (*read_buffer == 'C')
		{
			map->collectables++;
			columns++;
		}
		else if (*read_buffer == 'P')
		{
			map->players++;
			columns++;
		}
		else if (*read_buffer == '1' || *read_buffer == '0')
			columns++;
		else
		{
			map->lines++;
			if (columns == map->columns)
				columns = 0;
			else
				printf("O mapa não é retangular\n");
		}
		read(fd, read_buffer, BUFFER_SIZE);
	}
	map->lines++;
	printf("Linhas: %d\n", map->lines);
	printf("Columns: %d\n", map->columns);
	printf("Collectables: %d\n", map->collectables);
	printf("Players: %d\n", map->players);
	printf("Exit: %d\n", map->out);
*/