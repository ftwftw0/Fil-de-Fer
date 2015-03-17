#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:32:10 by flagoutt          #+#    #+#              #
#    Updated: 2015/03/05 17:13:25 by flagoutt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_init.c \
		srcs/ft_mktable.c \
		srcs/mlx_putline.c \
		srcs/mlx_putgrid.c \
		srcs/mlx_putpxl_img.c \
		srcs/mlx_create_img.c \
		srcs/mlx_key_hooks.c \
		srcs/ft_destroy.c \
		srcs/mlx_mouse_hooks.c 
SRCO = $(SRCS:.c=.o)
INCLUDE = -Iincludes/
LIBS = -L/usr/X11/lib -lmlx -lXext -lX11 -Llibft/ -lft -lm
NAME = fdf

all: $(NAME)

$(NAME):
	make -C libft/
	@echo "#####      Compile tooooouuuuut      #####"
	gcc -o $(NAME) main.c $(SRCS) $(FLAGS) $(INCLUDE) $(LIBS)

clean:
	make clean -C libft/
	rm -f $(SRCO)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re:	fclean all
