/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:50:26 by coder             #+#    #+#             */
/*   Updated: 2021/12/08 02:16:15 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ESC 65307
# define QUIT 113
# define A 97
# define W 119
# define S 115
# define D 100
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define CLICK_X 17
# define KEY_PRESS 2
# define KEY_PRESS_MASK 1L<<0

typedef struct s_data {
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;
} t_data;

typedef struct s_map {
	int	columns;
	int	lines;
	int	players;
	int	collectables;
	int	out;
} t_map;

int		close_window(t_data *data);
void	print_error(int signal);
int		key_map(int key, t_data *data);
int		render_next_frame(t_data *data);
int		count_map(t_map *map, char argv[]);

#endif