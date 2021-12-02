# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:56:43 by coder             #+#    #+#              #
#    Updated: 2021/12/02 16:13:21 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror
SRC_PATH = ./src
GNL_PATH = ./gnl
SRC = close_window.c key_map.c render.c main.c
GNL = get_next_line.c get_next_line_utils.c
FLAGS = -lmlx -lX11 -lXext

all:
	gcc $(CFLAGS) -o $(NAME) $(SRC_PATH)/*.c $(GNL_PATH)/*.c -I./includes $(FLAGS)
	