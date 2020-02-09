# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjohanso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 12:09:10 by wjohanso          #+#    #+#              #
#    Updated: 2020/02/09 12:11:49 by wjohanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# THIS IS A MAKEFILE FOR THE ROOT DIRECTORY OF A PROGRAM THAT USES LIBFT

NAME = libft.a
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

SRC = *
EXE = fillit
LIB_DIR = ./libft/

all: $(NAME)

$(NAME):
	@echo "Making the Library & moving to current directory..."||:
	@cd $(LIB_DIR) && gcc -Wall -Wextra -Werror -c $(FUNCT)||:
	@cd $(LIB_DIR) && ar rc $(NAME) *.o||:
	@mv $(LIB_DIR)$(NAME) .||:
	@echo "done"||:

clean:
	@echo "Removing object files..."||:
	@cd $(LIB_DIR) && rm -f *.o||:
	@rm -f *.o||:
	@echo "done"||:

fclean: clean
	@echo "Removing executable files & library..."||:
	@rm -f $(NAME) $(EXE)||:
	@echo "done"||:

re: fclean all

rerun: recompile fclean
	./$(EXE)
recompile: re compile

compile:
	@echo "Compiling all files w/ library..."||:
	@gcc -Wall -Wextra -Werror -c $(SRC).c||:
	@gcc $(SRC).o -L. -lft -o $(EXE)||:
	@echo "done"||:

