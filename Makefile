# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:56:43 by coder             #+#    #+#              #
#    Updated: 2021/12/11 00:11:57 by gcosta-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_PATH = ./includes/libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a
SRC_PATH = ./src/
SRC = $(SRC_PATH)close_window.c $(SRC_PATH)key_map.c \
		$(SRC_PATH)verifies.c $(SRC_PATH)load_image.c $(SRC_PATH)put_image.c \
		$(SRC_PATH)count_map.c
OBJ_PATH = ./objs/
CFLAGS = -Wall -Wextra -Werror
FLAGS = -lmlx -lX11 -lXext
OBJ = $(subst $(SRC_PATH),$(OBJ_PATH),$(SRC:%.c=%.o))

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -o $(NAME) ./src/main.c $(OBJ) $(FLAGS)

$(LIBFT_LIB): $(LIBFT_LIB) $(OBJ)
	$(MAKE) -C ./includes/libft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	gcc $(CFLAGS) -c $< -o $@