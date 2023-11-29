# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenlahb <abenlahb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 22:00:28 by abenlahb          #+#    #+#              #
#    Updated: 2023/10/06 22:00:28 by abenlahb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D
SRCS = ./src/cub3D.c ./src/secondrayutils.c ./src/firstrayutils.c  ./src/player.c ./src/init.c ./src/raycasting_partone.c ./src/raycasting_parttwo.c ./src/raycasting_partthree.c ./src/raycasting_partfour.c ./src/raycasting_partfive.c \
       ./src/utils.c ./get_next/get_next_line.c ./get_next/get_next_line_utils.c \
       ./src/map_function.c ./src/map_check.c ./src/utils2.c ./src/utils3.c ./src/parse.c \
	   ./src/utilis4.c

LIBS =  -L libft -lft 
OBJ = $(SRCS:.c=.o)
CC = cc 
CFLAGS =-Wextra -Werror -Wall  -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS)  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

.c.o:
	@$(CC)  $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@echo "\033[1;cub3D objects are deleted"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "\033[1;31cub3D is deleted"

re: fclean all
