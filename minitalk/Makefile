# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 17:26:02 by mfanelli          #+#    #+#              #
#    Updated: 2025/02/11 08:47:48 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEA = server
NAMEB = client
SOURCES = common_file.c server_utils.c client_utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -g

all : $(NAMEA) $(NAMEB)

$(NAMEA) : $(OBJECTS)
	@echo Compiling server...
	$(CC) server.c server_utils.o common_file.o $(FLAGS) -o $(NAMEA)

$(NAMEB) : $(OBJECTS)
	@echo Compiling client...
	$(CC) client.c client_utils.o common_file.o $(FLAGS) -o $(NAMEB)

clean:
	@echo Cleaning...
	rm -f $(OBJECTS)

fclean: clean
	@echo fCleaning...
	rm -f $(NAMEA)
	rm -f $(NAMEB)

re : fclean all


.PHONY: all clean fclean re
.SILENT: