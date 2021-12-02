/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:10 by coder             #+#    #+#             */
/*   Updated: 2021/12/02 16:16:43 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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