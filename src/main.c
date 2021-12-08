/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:56:47 by coder             #+#    #+#             */
/*   Updated: 2021/12/08 01:41:06 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


//gcc -Wall -Werror -Wextra -o so_long main.c -lmlx -lXext -lX11 && ./so_long

char	*ft_strnstr(const char *s1, const char *s2, size_t	n);

int	main(int argc, char *argv[])
{
	t_data	data;
	t_map map;
	int lines;

	char	*relative_path = "./pixel_pack_dungeon/heroes/knight_idle_anim_f0.xpm";

	if (argc != 2)
	{
		printf("cheguei no argc\n");
		return (0);
	}
	if (!ft_strnstr(argv[1], ".ber", 15))
	{
		printf("Cheguei no argv\n");
		return (0);
	}

	lines = count_map(&map, argv[1]);
	printf("lines: %d\n", map.lines);
	printf("col: %d\n", map.columns);


	/*
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 600, 600, "Testinho");

	data.img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &data.img_width, &data.img_height);

	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, data.img_width, data.img_height);

	mlx_hook(data.mlx_win, KEY_PRESS, KEY_PRESS_MASK, key_map, &data);
	mlx_hook(data.mlx_win, CLICK_X, 0, close_window, &data);
	mlx_loop_hook(data.mlx_win, render_next_frame, &data);
	mlx_loop(data.mlx_ptr);
	*/
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