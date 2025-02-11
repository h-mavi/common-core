# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 17:26:02 by mfanelli          #+#    #+#              #
#    Updated: 2025/02/11 09:22:05 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEA = server
NAMEB = client
SOURCES = server_utils.c client_utils.c
OBJECTS = $(SOURCES:.c=.o)

SOURCES_BONUS = common_file_bonus.c client_utils_bonus.c server_utils_bonus.c
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -g

all : $(NAMEA) $(NAMEB)

bonus : $(OBJECTS_BONUS)
	@echo Compiling bonus...
	$(CC) server_bonus.c server_utils_bonus.o common_file_bonus.o $(FLAGS) -o $(NAMEA)
	$(CC) client_bonus.c client_utils_bonus.o common_file_bonus.o $(FLAGS) -o $(NAMEB)

$(NAMEA) : $(OBJECTS)
	@echo Compiling server...
	$(CC) server.c server_utils.o $(FLAGS) -o $(NAMEA)

$(NAMEB) : $(OBJECTS)
	@echo Compiling client...
	$(CC) client.c client_utils.o $(FLAGS) -o $(NAMEB)

clean:
	@echo Cleaning...
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)

fclean: clean
	@echo fCleaning...
	rm -f $(NAMEA)
	rm -f $(NAMEB)

re : fclean all


.PHONY: all bonus clean fclean re
.SILENT: