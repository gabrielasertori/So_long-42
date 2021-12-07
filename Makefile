# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:56:43 by coder             #+#    #+#              #
#    Updated: 2021/12/07 15:31:39 by gcosta-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
SRC_PATH = ./src
GNL_PATH = ./gnl
SRC = close_window.c key_map.c render.c main.c
GNL = get_next_line.c get_next_line_utils.c
#FLAGS = -I. -g3 -lbsd -lmlx -Ilmlx -lXext -lX11
FLAGS = -lmlx -lX11 -lXext

all:
	gcc -g3 -o $(NAME) $(SRC_PATH)/*.c $(GNL_PATH)/*.c -I./includes $(FLAGS)
	./so_long maps/map1.ber
