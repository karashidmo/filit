# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 14:09:16 by bhamdi            #+#    #+#              #
#    Updated: 2017/08/14 12:22:47 by krashid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -g -Werror -Wall -Wextra

SRC = ft_memalloc.c ft_putchar.c ft_putendl.c ft_putstr.c ft_strcpy.c \
	  ft_strjoin.c ft_strlen.c filecreator.c grid_test.c ft_memset.c \
	  move_tetri.c mapping.c  resolve.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
