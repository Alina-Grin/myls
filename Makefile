# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/06 14:39:50 by szeftyr           #+#    #+#              #
#    Updated: 2020/10/11 18:50:59 by szeftyr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = dirs.c flags.c ft_ls.c full_print.c print.c \
	   secondary.c sort_by_time.c sort.c get_stat.c

DIR = libft/libft.a

OBJS = $(SRCS:.c=.o)

NAME = ft_ls

.PHONY: all
all: $(NAME)

$(NAME): $(DIR) $(OBJS)
	$(CC) $(OBJS) libft/libft.a -o $(NAME)

$(DIR):
	# cd libft && $(MAKE)
	make -C libft

%.o: %.c ft_ls.h
	$(CC) -c $(CFLAGS) $<

.PHONY: clean
clean:
	@rm -f $(OBJS)
	make -C libft/ clean

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	make -C libft/ fclean

.PHONY: re
re: fclean all
