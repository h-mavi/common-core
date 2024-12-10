# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 08:12:03 by mfanelli          #+#    #+#              #
#    Updated: 2024/12/10 16:46:10 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SOURCES = get_next_line_utils.c get_next_line.c get_next_line.h

CC = cc
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=42 -g

all : $(NAME) exe fclean

$(NAME) : $(SOURCES)
	@echo "Dammi un attimo che ti creo $(NAME)"
	$(CC) $(CFLAGS) $(SOURCES)

exe : $(NAME)
	./$(NAME)

fclean :
	@echo "viaaaa"
	rm -f $(NAME)

re : fclean all

.PHONY: all exe fclean re
.SILENT: