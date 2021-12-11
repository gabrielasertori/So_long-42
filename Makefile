# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 15:56:43 by coder             #+#    #+#              #
#    Updated: 2021/12/11 18:09:01 by gcosta-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC_PATH = ./src/
SRC = $(SRC_PATH)close_window.c \
		$(SRC_PATH)key_map.c \
		$(SRC_PATH)verifies.c \
		$(SRC_PATH)load_image.c \
		$(SRC_PATH)put_image.c \
		$(SRC_PATH)count_map.c
OBJ_PATH = ./objs/
OBJ = $(subst $(SRC_PATH),$(OBJ_PATH),$(SRC:%.c=%.o))

NAME_BONUS = so_long_bonus
SRC_BONUS_PATH = ./src_bonus/
B_INIT = $(SRC_BONUS_PATH)main_bonus.c
SRC_BONUS = $(SRC_BONUS_PATH)close_window_bonus.c \
		$(SRC_BONUS_PATH)key_map_bonus.c \
		$(SRC_BONUS_PATH)verifies_bonus.c \
		$(SRC_BONUS_PATH)load_image_bonus.c \
		$(SRC_BONUS_PATH)put_image_bonus.c \
		$(SRC_BONUS_PATH)count_map_bonus.c \
		$(SRC_BONUS_PATH)put_image_2_bonus.c
OBJ_BONUS_PATH = ./objs_bonus/
OBJ_BONUS = $(subst $(SRC_BONUS_PATH),$(OBJ_BONUS_PATH),$(SRC_BONUS:%.c=%.o))

FLAGS = -lmlx -lX11 -lXext
CFLAGS = -Wall -Wextra -Werror
SUCCESS = echo "\033[41m\033[32m*.SUCCESS.*\033[0m"

LIBFT_PATH = ./includes/libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p objs
	gcc $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_PATH)%.o: $(SRC_BONUS_PATH)%.c
	mkdir -p objs_bonus
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	echo "\033[41m\033[32m*.PREPARING REEINDERS.*\033[0m"
	$(MAKE) -C $(LIBFT_PATH)
	echo "\033[41m\033[32m*.SETTLING THE SLED.*\033[0m"
	gcc $(CFLAGS) -o $(NAME) ./src/main.c $(OBJ) $(LIBFT_LIB) $(FLAGS)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT_PATH)
	gcc $(CFLAGS) -o $(NAME_BONUS) $(B_INIT) $(OBJ_BONUS) $(LIBFT_LIB) $(FLAGS)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJ)
	$(SUCCESS)

clean_bonus:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJ_BONUS)
	$(SUCCESS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -rf $(OBJ_PATH)
	rm -f $(NAME)
	$(SUCCESS)

fclean_bonus: clean_bonus
	rm -rf $(OBJ_BONUS_PATH)
	rm -f $(NAME_BONUS)
	$(SUCCESS)

re: fclean all

re_bonus: fclean_bonus bonus