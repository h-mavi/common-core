# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 13:03:59 by mfanelli          #+#    #+#              #
#    Updated: 2025/02/25 11:28:41 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES = main.c utils.c tasks.c more.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -g -pthread

all : $(NAME)

$(NAME) : $(OBJECTS)
	@echo Compiling...
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	@echo Cleaning...
	rm -f $(OBJECTS)

fclean: clean
	@echo fCleaning...
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
.SILENT: