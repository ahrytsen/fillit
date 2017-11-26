#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/03 20:19:57 by ahrytsen          #+#    #+#              #
#    Updated: 2017/11/26 14:41:00 by ahrytsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			= gcc
CFLAGS		= -Wextra -Werror -Wall
NAME		= fillit
SRC 		= main.c input.c output.c fillit.c
OBJ 		= $(SRC:.c=.o)
HDR 		= fillit.h
LIB 		= libft/libft.a

all: lib $(NAME)

$(NAME): $(LIB) $(OBJ) $(HDR)
	$(CC) $(CFLAGS) -o $(NAME) $(LIB) $(OBJ)

lib:
	make -C libft

$(LIB): lib

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.NOTEPARALLEL: all $(NAME) re
