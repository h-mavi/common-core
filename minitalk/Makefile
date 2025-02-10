# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 17:26:02 by mfanelli          #+#    #+#              #
#    Updated: 2025/02/10 10:04:51 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEA = server

NAMEB = client

CC = cc
FLAGS = -Wall -Wextra -Werror -g

all : $(NAMEA) $(NAMEB)

$(NAMEA):
	@echo Compiling server...
	$(CC) server.c server_utils.c common_file.c $(FLAGS) -o $(NAMEA)

$(NAMEB):
	@echo Compiling client...
	$(CC) client.c client_utils.c common_file.c $(FLAGS) -o $(NAMEB)

clean:
	@echo Cleaning...

fclean: clean
	@echo fCleaning...
	rm -f $(NAMEA)
	rm -f $(NAMEB)

re : fclean all


.PHONY: all clean fclean re
.SILENT: