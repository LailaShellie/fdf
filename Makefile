# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshellie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 16:13:26 by lshellie          #+#    #+#              #
#    Updated: 2019/08/13 16:13:27 by lshellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c validation.c map.c start.c make_map.c draw_line.c keyboard.c position.c angle.c bresenham.c wu.c

OBJ = main.o validation.o map.o start.o make_map.o draw_line.o keyboard.o position.o angle.o bresenham.o wu.o

NAME = fdf

LIB = libft.a

MLX = mlx

all: $(NAME)

$(NAME): $(OBJ) $(LIB) $(MLX)
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -lm -L. libft/$(LIB) -L ./mlx -lmlx -framework OpenGL -framework AppKit
$(LIB):
	make -C ./libft
$(MLX):
	make -C ./mlx
%.o: %.c
	gcc -c $<
clean:
	make clean -C ./libft
	rm -rf $(OBJ)
fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)
make re: fclean all