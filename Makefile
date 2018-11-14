# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 14:34:18 by eschnell     #+#   ##    ##    #+#        #
#    Updated: 2018/11/14 17:18:35 by matheme     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = fillit

SRC = main.c fillit.c error.c utils.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -I. -L./libft -lft -o $(NAME) $(OBJ)

$(OBJ):
		$(CC) $(CFLAGS) -c $(SRC)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
