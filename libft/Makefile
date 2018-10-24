NAME	= libft.a
DNAME	= libft.so
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -Iincludes -c
FILES	= $(shell find . -name "*.c")
OBJ		= $(FILES:.c=.o)


all: $(NAME)

# This won't run if the .o files don't exist or are not modified
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo \# Static libft.a
	@echo "\033[32m[✓] LIBFT COMPILED\033[0m"

so:
	gcc -shared -fPIC -Wl,-soname,$(DNAME) -o $(DNAME) $(OBJ) -lc
	@echo \# Dynamic libft.so

$(OBJ):
	gcc $(CFLAGS) $(FILES)

clean:
	rm -f *.o
	@echo "\033[31m[✘] object files deleted\033[0m"

fclean: clean
	rm -f $(NAME) $(DNAME)
	@echo "\033[31m[✘] $(NAME) && $(DNAME) deleted\033[0m"

re: fclean all

.PHONY: clean fclean all re
