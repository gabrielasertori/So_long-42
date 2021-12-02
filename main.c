#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>


//gcc -Wall -Werror -Wextra -o so_long main.c -lmlx -lXext -lX11 && ./so_long
#define ESC 65307
#define QUIT 113
#define A 97
#define W 119
#define S 115
#define D 100
#define ARROW_UP 65362
#define ARROW_DOWN 65364
#define ARROW_LEFT 65361
#define ARROW_RIGHT 65363
#define CLICK_X 17
#define KEY_PRESS 2
#define KEY_PRESS_MASK 1L<<0

typedef struct s_data {
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
} t_data;



int	close_window(t_data *data);
int	key_map(int key, t_data *data);
int render_next_frame(t_data *data);

int	main(void)
{
	t_data	data;

	char	*relative_path = "./pixel_pack_dungeon/heroes/knight_idle_anim_f0.xpm";
	int		img_width;
	int		img_height;

	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 600, 600, "Testinho");
	data.img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &img_width, &img_height);

	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 100, 100);
	mlx_hook(data.mlx_win, KEY_PRESS, KEY_PRESS_MASK, key_map, &data);
	mlx_hook(data.mlx_win, CLICK_X, 0, close_window, &data);
	mlx_loop_hook(data.mlx_win, render_next_frame, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int render_next_frame(t_data *data)
{
	printf("hello");
	printf("%p", data->mlx_ptr);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	printf("Au revoir\n");
	exit(0);
	return (0);
}

int	key_map(int key, t_data *data)
{
	if (key == ESC || key == QUIT)
		close_window(data);
	else if (key == 'a' || key == ARROW_LEFT)
	{
		printf("a %d\n", key);
		render_next_frame(data);
	}
	else if (key == 'w' || key == ARROW_UP)
		printf("w %d\n", key);
	else if (key == 's' || key == ARROW_DOWN)
		printf("s %d\n", key);
	else if (key == 'd' || key == ARROW_RIGHT)
		printf("d %d\n", key);
	else
		printf("%d\n", key);
	return (0);
}