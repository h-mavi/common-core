# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 13:03:59 by mfanelli          #+#    #+#              #
#    Updated: 2025/02/19 11:29:09 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES = main.c utils.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread -g

all : $(NAME)

$(NAME) : $(OBJECTS)
	@echo Compiling...
	$(CC) $(OBJECTS) $(FLAGS) -o $(NAME)

clean:
	@echo Cleaning...
	rm -f $(OBJECTS)

fclean: clean
	@echo fCleaning...
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
.SILENT: