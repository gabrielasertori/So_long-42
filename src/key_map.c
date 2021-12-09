/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:54:10 by coder             #+#    #+#             */
/*   Updated: 2021/12/08 21:38:00 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_map(int key, t_global *global)
{
	if (key == ESC || key == QUIT)
		close_window(global);
	else if (key == 'a' || key == ARROW_LEFT)
	{
		printf("a %d\n", key);
		//render_next_frame(global);
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