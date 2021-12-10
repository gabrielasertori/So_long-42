# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:56:43 by coder             #+#    #+#              #
#    Updated: 2021/12/10 20:02:10 by gcosta-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
SRC_PATH = ./src
SRC = close_window.c key_map.c main.c verifies.c load_image.c put_image.c \
		count_map.c
GNL = get_next_line.c get_next_line_utils.c
CFLAGS = -Wall -Wextra -Werror
FLAGS = -lmlx -lX11 -lXext

OBJ = $(subst $(SRC_PATH),$(OBJ_PATH),$(SRC:.c=.o))

all: $(NAME)
	gcc -o $(NAME) $(SRC_PATH)/*.c $(GNL_PATH)/*.c -I./includes $(FLAGS)
	./so_long maps/map1.ber

$(LIBFT):
	$(MAKE) -C ./libft
	ar -rc

#LIBFT_PATH     = ./libs/libft LIBFT    = $(LIBFT_PATH)/libft.a LIBFT_FLAGS = -L$(LIBFT_PATH) -lft