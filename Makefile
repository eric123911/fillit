# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 14:34:18 by eschnell     #+#   ##    ##    #+#        #
#    Updated: 2018/11/19 17:07:00 by matheme     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= fillit
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -Iincludes
LIB		= libft/libft.a
SRCS	:= $(wildcard $(addsuffix *.c,src/))
OBJS	:= $(patsubst %.c,%.o,$(SRCS))


all: $(LIB) $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

$(OBJS): %.o : %.c

$(LIB):
		@make -C libft/ re
		@make -C libft/ clean

clean:
		rm -f src/*.o

fclean: clean
		rm -f $(NAME) $(LIB)

re: fclean all
