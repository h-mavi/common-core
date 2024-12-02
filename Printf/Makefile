# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 17:51:13 by mfanelli          #+#    #+#              #
#    Updated: 2024/12/02 09:12:28 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf ft_putchar.c ft_putnbr.c ft_putstr.c ft_unsigned_putnbr.c


OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

$(NAME) : $(OBJECTS)
	@echo "Compiling $(NAME)"
	ar -rcs $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<
	
clean :
	rm -f $(OBJECTS)
fclean : clean
	rm -f $(NAME)

all : $(NAME)
re : fclean all

.PHONY: all clean fclean bonus re
.SILENT: