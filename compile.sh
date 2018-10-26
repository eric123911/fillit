#!/bin/sh

set -o errexit

gcc -g3 -Wall -Werror -Wextra -o fillit \
	main.c \
	error.c \
	libft/libft.a
