# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:56:43 by coder             #+#    #+#              #
#    Updated: 2021/12/11 00:28:17 by gcosta-d         ###   ########.fr        #
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

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p objs
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_PATH)
	gcc $(CFLAGS) -o $(NAME) ./src/main.c $(OBJ) $(LIBFT_LIB) $(FLAGS)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rmdir $(OBJ_PATH)
	rm -f $(NAME)
