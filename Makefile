# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 12:00:43 by gkrusta           #+#    #+#              #
#    Updated: 2023/08/26 16:52:48 by gkrusta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror -g


LIBFT_PATH = libraries/libft/
LIBFT = $(LIBFT_PATH)/libft.a
HEADERS = -I ./inc -I ./libraries/MLX42/include/MLX42 -I ./libraries/libft

MLX42_PATH = libraries/MLX42/
MLX42 = $(MLX42_PATH)/libmlx42.a

SRCS =  $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(MLX42) $(NAME) 

$(NAME): $(OBJS)
	@ echo "\033[32mCompiling Fractol...\n"
	@$(CC) $(FLAGS) $(OBJS) $(MLX42) $(LIBFT) -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" $(HEADERS) -o $@
	@ echo "\n\t\t\033[32mCompiled!\n"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

$(LIBFT):
	@ make -C $(LIBFT_PATH)
	@ echo "\n\t\t\033[32mCreated libft!\n"

$(MLX42):
	@ make -C $(MLX42_PATH)
	@ echo "\n\t\t\033[32mCreated Minilibx!\n"

RM = rm -f

clean:
	@ $(RM) $(OBJS) 
	@ make -C $(LIBFT_PATH) clean
	@ make -C $(MLX42_PATH) clean
	@ echo "\n\t\t\033[32mEverything is clean!\n"

fclean: clean
	@ $(RM) $(NAME)
	@ make -C $(LIBFT_PATH) fclean
	@ make -C $(MLX42_PATH) fclean

re: fclean all

.PHONY: all clean fclean re