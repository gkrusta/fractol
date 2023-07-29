# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkrusta <gkrusta@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 16:20:08 by gkrusta           #+#    #+#              #
#    Updated: 2023/07/18 14:05:37 by gkrusta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB = ar rcs

SRCS = ft_bzero.c  ft_isalnum.c ft_memcpy.c \
	  ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_memset.c  ft_strlen.c \
	  ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c \
	  ft_strrchr.c ft_strncmp.c ft_memchr.c \
	  ft_strnstr.c ft_atoi.c    ft_calloc.c \
	  ft_strdup.c  ft_memcmp.c  ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c    ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_long_atoi.c \
	  ft_strcmp.c ft_lstnew.c ft_lstadd_front.c \
	  ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	  ft_putchar.c ft_putstr.c ft_decimal.c \
	  ft_us_decimal.c ft_hexadec.c ft_void_ptr.c \
	  ft_printf.c \
	  get_next_line.c get_next_line_utils.c


OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re