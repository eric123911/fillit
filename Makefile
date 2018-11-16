# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 14:34:18 by eschnell     #+#   ##    ##    #+#        #
#    Updated: 2018/11/16 20:20:44 by eschnell    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = fillit

SRC = main.c fillit.c error.c utils.c free_all.c option.c unicode.c

OBJ = $(SRC:.c=.o)


all: lib $(NAME)

$(NAME): $(OBJ)
		$(CC) -I. -o $(NAME) $(OBJ) -Llibft -lft

$(OBJ):
		$(CC) $(CFLAGS) -c $(SRC)

lib:
		make -C libft/ re
		make -C libft/ clean

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME) libft/libft.a

re: fclean all
