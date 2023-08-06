# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleepago <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 08:44:03 by pleepago          #+#    #+#              #
#    Updated: 2023/08/06 12:13:37 by pleepago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# CFLAGS = -Wall -Wextra -Werror -g 
CFLAGS = -g 
CC = gcc

FILES = ft_gnl/get_next_line.c ft_gnl/get_next_line_utils.c main.c read_map.c render.c drawing.c\
control.c
MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJ	:= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx/
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(MLX_FLAG)

clean:
	@make clean -C mlx/
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re norm%       