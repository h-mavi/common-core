# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 10:25:46 by mfanelli          #+#    #+#              #
#    Updated: 2025/03/11 11:51:29 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCES = utils.c tasks.c ripper.c more.c main.c
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