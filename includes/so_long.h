/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:05:05 by gcosta-d          #+#    #+#             */
/*   Updated: 2021/12/13 00:05:06 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFFER_SIZE 1
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
# define SIZE_IMG 64
# define PLAYER_FRONT "./assets/player_front.xpm"
# define PLAYER_BACK "./assets/player_back.xpm"
# define PLAYER_LEFT "./assets/player_left.xpm"
# define PLAYER_RIGHT "./assets/player_right.xpm"
# define EXIT_OPEN "./assets/exit_open.xpm"
# define EXIT_BLOCK "./assets/exit_block.xpm"
# define PATH "./assets/path.xpm"
# define WALL "./assets/wall.xpm"
# define COLECT "./assets/colect.xpm"

typedef struct s_data {
	void	*mlx_ptr;
	void	*mlx_win;
	int		img_width;
	int		img_height;
	void	*img_colect;
	void	*img_exit_block;
	void	*img_exit_open;
	void	*img_path;
	void	*img_player_back;
	void	*img_player_front;
	void	*img_player_right;
	void	*img_player_left;
	void	*img_wall;
	int		pos_col;
	int		pos_line;
	int		end_game;
}	t_data;

typedef struct s_map {
	char	**matrix;
	int		columns;
	int		lines;
	int		players;
	int		collectables;
	int		out;
	int		moves;
}	t_map;

typedef struct s_global
{
	t_data	*data;
	t_map	*map;
}	t_global;

int		close_window(t_global *global);
void	free_matrix(t_global *global);
void	print_error(int signal, t_global *global);
int		key_map(int key, t_global *global);
int		render_next_frame(t_global *global);
int		count_map(t_global *global, char argv[]);
int		verify_first_and_last(t_global *global);
void	verify_map(t_global *global);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *s1, const char *s2, size_t	n);
void	load_image(t_global *global);
void	free_images(t_global *global);
int		put_images(t_global *global);

#endif