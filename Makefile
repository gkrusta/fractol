# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 12:00:43 by gkrusta           #+#    #+#              #
#    Updated: 2023/07/29 12:13:56 by gkrusta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FRAECTOL = ar rcs

SRCS =  mandelbrot.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@ echo "\033[32mCompiling Fractol...\n"
	@ make -C libft1/ all
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJS) libft1/libft.a
	@ echo "\n\t\t\033[32mCompiled!\n"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJS) 
	@ make -C libft1/ clean
	@ make -C MLX42/ clean
	@ echo "\n\t\t\033[32mEverything is clean!\n"

fclean: clean
	@ $(RM) $(NAME)
	@ make -C libft1/ fclean
	@ make -C MLX42/ fclean

re: fclean all bonus

.PHONY: all clean fclean re