# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 11:59:03 by szeftyr           #+#    #+#              #
#    Updated: 2020/10/07 12:42:51 by szeftyr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	   ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar.c ft_putstr.c \
	   ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
	   ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	   ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c \
	   ft_memalloc.c ft_putnbr.c ft_putchar_fd.c ft_putnbr_fd.c \
	   ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_itoa.c ft_strjoin.c \
	   ft_strequ.c ft_strnequ.c ft_memdel.c ft_strnew.c ft_strdel.c \
	   ft_strclr.c ft_strtrim.c ft_striter.c ft_striteri.c ft_strmap.c \
	   ft_strmapi.c ft_strsub.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c \
	   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	   ft_strrev.c ft_lstlast.c ft_lstrev.c ft_lstnel.c ft_lstntail.c \
	   ft_lstappend.c ft_lstlen.c ft_shakersort.c ft_lstfree.c ft_ndigit.c

INCLUDES = libft.h

OBJS = $(SRCS:.c=.o)

NAME = libft.a

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(SRCS) -I$(INCLUDES) $<

.PHONY: clean
clean:
	@rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)

.PHONY: re
re: fclean all
