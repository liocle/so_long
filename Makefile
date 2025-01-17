# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: lclerc <marvin@42.fr>                      +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 10:18:50 by lclerc            #+#    #+#              #
#    Updated: 2023/05/13 11:23:00 by lclerc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
# $@ and $^ are special variables that represent the target and the first
# dependency:
# - $@ represents the target, the file being built.
# - $< represents the first dependency, the file required to build the target.
#
#******************************************************************************#

BINARY = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLX_LINK = -L ./mlx/ -lmlx -lX11 -lXext -lm
MLX = mlx/libmlx.a
COMPILE = $(CC) $(CFLAGS)
SRCDIR = ./src/
DIRLIBFT = ./libft/
DIRMLX = ./mlx/
SRCS = $(addprefix $(SRCDIR), \
	   map_build.c \
	   error_exit.c \
	   utils_to_be_deleted.c \
	   map_validation.c \
	   map_validation_2.c \
	   game_init.c \
	   gaming_movement.c \
	   gaming_movement_2.c \
	   main.c)
LIBFTLIB = ./libft/libft.a
OBJ = $(SRCS:%.c=%.o)

#******************************************************************************#

all: $(BINARY)

$(BINARY): $(MLX) $(LIBFTLIB) $(OBJ)
	$(COMPILE) $(OBJ) $(MLX) $(MLX_LINK) $(LIBFTLIB) -o $(BINARY)

%.o: %.c
	$(COMPILE) -I libft $< -c -o $@

$(LIBFTLIB):
	make -C ./libft/

$(MLX):
	make -C ./mlx/

#******************************************************************************#

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean
	make -C mlx clean

fclean: clean
	/bin/rm -f $(BINARY)
	make -C libft fclean

re: fclean all

#******************************************************************************#
.PHONY: all clean fclean re
#******************************************************************************#
