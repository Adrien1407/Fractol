# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 17:21:29 by adlancel          #+#    #+#              #
#    Updated: 2021/07/20 17:03:46 by adlancel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CCF = clang -Wall -Wextra -Werror
FLAGS = -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -lbsd

OBJ_DIR = objs
SRC_DIR = srcs

SRC_F = main.c \
				exit_and_free.c \
				ft_strncmp.c \
				init_fractal.c \
				init_mlx.c \
				mandelbrot_magic.c \
				my_mlx_pixel_put.c \
				power_2.c \
				set_hooks.c \
				get_key_press.c \
				get_mouse_scroll.c \


SRC = $(addprefix $(SRC_DIR)/,$(SRC_F))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_F:%.c=%.o))

HEADER = include

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx_linux
	$(CCF) -o $(NAME) $(OBJ) $(FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CCF) -I /usr/include -I mlx_linux -I $(HEADER) -O3 -c $< -o $@

clean:
	rm -rf mlx_linux/obj
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f mlx_linux/libmlx.a mlx_mlx_Linux.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
