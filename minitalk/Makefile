# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 17:26:02 by mfanelli          #+#    #+#              #
#    Updated: 2025/02/05 17:30:02 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEA = server

NAMEB = client

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft -Iprintf -Llibft -Lprintf

all : $(NAMEA) $(NAMEB)

$(NAMEA):
	make libft
	make printf
	$(CC) server.c printf/libftprintf.a libft/libft.a $(FLAGS) -o $(NAMEA)

$(NAMEB):
	make libft
	make printf
	$(CC) client.c printf/libftprintf.a libft/libft.a $(FLAGS) -o $(NAMEB)

clean:
	@echo Cleaning...
	make clean -C libft
	make clean -C printf

fclean: clean
	@echo fCleaning...
	make fclean -C libft
	make fclean -C printf
	rm -f $(NAMEA)
	rm -f $(NAMEB)

re : fclean all

printf:
	@echo Compiling Printf...
	make -C printf/

libft:
	@echo Compiling Libft...
	make -C libft/

.PHONY: all clean fclean re printf libft
.SILENT: