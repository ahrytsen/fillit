#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/03 20:19:57 by ahrytsen          #+#    #+#              #
#    Updated: 2017/11/23 13:05:58 by ahrytsen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
SRC = main.c input.c output.c fillit.c
OBJ = $(SRC:.c=.o)
HDR = fillit.h
LIB = libft/libft.a

all: $(SRC) $(NAME)

$(NAME): $(OBJ) $(HDR)
	@make -C libft/;
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) $(LIB);

.c.o:
	@gcc -Wall -Wextra -Werror -c $<

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

.NOTEPARALLEL: all $(NAME) re
