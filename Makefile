# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 12:09:10 by wjohanso          #+#    #+#              #
#    Updated: 2020/03/02 19:32:39 by wjohanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# THIS IS A MAKEFILE FOR THE ROOT DIRECTORY OF A PROGRAM THAT USES LIBFT

LIB_NAME = libft.a
FUNCT = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		ft_strncat.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcat.c ft_strchr.c\
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_find_magnitude.c\
		ft_is_negative.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c get_next_line.c 

SRC = fillit.c find_minmapsize.c input_map_store.c t_blocks_init.c\
	  t_blocks_store.c valid_tetris.c adjacency.c inputmap_reset.c\
	  t_blocks_newnode.c normalize.c t_blocks_position.c solver.c map.c map_two.c

EXE = fillit
LIB_DIR = ./libft/
NAME = fillit
DEBUG = -ggdb -fsanitize=address -fno-omit-frame-pointer

all: $(NAME) 

$(NAME): 
	@echo "Making the Library & moving library to current directory"||:
	@cd $(LIB_DIR) && gcc -Wall -Wextra -Werror -c $(FUNCT)||:
	@cd $(LIB_DIR) && ar rc $(LIB_NAME) *.o||:
	@mv $(LIB_DIR)$(LIB_NAME) .||:
	@echo "Compiling all files w/ library"||:
	@gcc -Wall -Wextra -Werror -c $(SRC)||:
	@gcc *.o -L. -lft -o $(EXE)||:

clean:
	@echo "Removing object files"||:
	@cd $(LIB_DIR) && rm -f *.o||:
	@rm -f *.o||:

fclean: clean
	@echo "Removing executable files & library"||:
	@rm -f $(LIB_NAME) $(EXE)||:

re: fclean all

memory_test: fclean
	@echo "Making the Library & moving library to current directory"||:
	@cd $(LIB_DIR) && gcc -Wall -Wextra -Werror -c $(FUNCT)||:
	@cd $(LIB_DIR) && ar rc $(LIB_NAME) *.o||:
	@mv $(LIB_DIR)$(LIB_NAME) .||:
	@echo "Compiling all files w/ library"||:
	@gcc $(DEBUG) -Wall -Wextra -Werror -c $(SRC)||:
	@gcc $(DEBUG) *.o -L. -lft -o $(EXE)||:
