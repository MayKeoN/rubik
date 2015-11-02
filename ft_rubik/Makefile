#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymonfray <ymonfray@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/25 20:26:03 by ymonfray          #+#    #+#              #
#    Updated: 2015/10/25 20:26:04 by ymonfray         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = rubik

SRC =	src/ft_rubik_init.c\
		src/ft_rubik_main.c\
		src/ft_rubik_rotate.c\
		src/ft_rubik_jungle.c\
		src/ft_rubik_print.c
		# src/ft_rubik_draw.c\
		# src/ft_rubik_init.c

INC = -I include -I libft/include 
#-I ~/work/tools/sdl/include/SDL2/ -I ~/work/tools/glfw/include/

#MACFW = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

#LIB = -L ~/work/tools/sdl/lib/ -lSDL2 -L ~/work/tools/glfw/lib/ -lglfw3 -L 

LIB = -L ~/work/tools/libft -lft

HEAD = include/ft_rubik.h

OBJ = $(SRC:.c=.o)

FLAG = -O1

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(INC) $(LIB)

%.o: %.c
	$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all