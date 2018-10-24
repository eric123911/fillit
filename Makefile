
CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = fillit

SRC = main.c fillit.c error.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $(NAME) $(OBJ)

$(OBJ):
		$(CC) $(CFLAGS) -c $(SRC)

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
