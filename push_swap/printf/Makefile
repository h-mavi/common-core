# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 17:51:13 by mfanelli          #+#    #+#              #
#    Updated: 2025/02/07 10:59:03 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_check.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbrhex_max.c \
ft_putnbrhex_min.c ft_putnbrhex_ptr.c ft_putptr.c ft_putstr.c \
ft_unsigned_putnbr.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<
	
clean :
	rm -f $(OBJECTS)
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean bonus re
.SILENT: