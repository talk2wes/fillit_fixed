# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 15:48:40 by wjohanso          #+#    #+#              #
#    Updated: 2020/02/07 11:37:33 by wjohanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNCT = fillit.c valid_tetris.c 
EXE = fillit
LIB_DIR = ./libft

all: $(NAME)

$(NAME):
	cd $(LIB_DIR) && make
	gcc -Wall -Wextra -Werror -c $(FUNCT)
	
clean:

fclean: clean
	
