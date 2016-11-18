# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/20 18:36:08 by iwithmor          #+#    #+#              #
#    Updated: 2016/10/20 18:42:58 by iwithmor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LDIR = ./libft
IDIR = .
LIB = $(LDIR)/libft.a
FINDLIB = -L$(LDIR) -lft
SRC = main.c process_file.c read_file.c buf_concat.c validate_tetromino.c \
store_data.c count_tetrominos.c tetromino_type.c shapes.c fillit.c link_data.c \
shape_coordinates.c map.c solve_helpers.c ft_lstlen_counter.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(FINDLIB) -o $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC) -I$(IDIR) -I$(LDIR)

$(SRC): $(LIB)

$(LIB):
	make -C $(LDIR)

clean:
	make clean -C $(LDIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LDIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
