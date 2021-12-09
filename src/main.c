/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:56:47 by coder             #+#    #+#             */
/*   Updated: 2021/12/09 21:13:45 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


//gcc -Wall -Werror -Wextra -o so_long main.c -lmlx -lXext -lX11 && ./so_long

char	*ft_strnstr(const char *s1, const char *s2, size_t	n);

int	main(int argc, char *argv[])
{
	t_global	global;
	int			lines;

	global.map = malloc(sizeof(t_map) * 1);
	global.data = malloc(sizeof(t_data) * 1);
	global.map->collectables = 0;
	global.map->players = 0;
	global.map->out = 0;
	if (argc != 2)
		print_error(5, &global);
	if (!ft_strnstr(argv[1], ".ber", 15))
		print_error(5, &global);
	count_map(&global, argv[1]);

	global.data->mlx_ptr = mlx_init();
	global.data->mlx_win = mlx_new_window(global.data->mlx_ptr, global.map->lines * SIZE_IMG, global.map->columns * SIZE_IMG, "Testinho");
	load_image(&global);
	mlx_put_image_to_window(global.data->mlx_ptr, global.data->mlx_win, global.data->img_player_front, global.data->img_width, global.data->img_height);
/*
	mlx_loop_hook(data.mlx_win, render_next_frame, &data);
*/
	mlx_hook(global.data->mlx_win, KEY_PRESS, KEY_PRESS_MASK, key_map, &global);
	mlx_hook(global.data->mlx_win, CLICK_X, 0, close_window, &global);
	mlx_loop(global.data->mlx_ptr);
	return (0);
}


char	*ft_strnstr(const char *s1, const char *s2, size_t	n)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen(s2);
	if (!s2_len)
		return ((char *)s1);
	if (n != 0)
	{
		while (s1[i] && i <= n - s2_len)
		{
			j = 0;
			while (s2[j] && s2[j] == s1[i + j])
				j++;
			if (j == s2_len)
				return ((char *)&s1[i]);
			i++;
		}
	}
	return (NULL);
}