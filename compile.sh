#!/bin/sh

set -o errexit

gcc -Wall -Werror -Wextra -o fillit \
	main.c \
	error.c \
	libft/libft.a
