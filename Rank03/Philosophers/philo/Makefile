# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 10:25:46 by mfanelli          #+#    #+#              #
#    Updated: 2025/03/13 11:16:26 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES = utils.c tasks.c ripper.c more.c main.c bruh.c
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
#.SILENT: