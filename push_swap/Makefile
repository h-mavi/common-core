# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 10:45:58 by mfanelli          #+#    #+#              #
#    Updated: 2025/01/31 09:23:27 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = main.c push_swap_utils.c utils.c bruh.c operation.c still_operation.c \
algorithm_1.c special_cases.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft -Iprintf -Llibft -Lprintf

all : $(NAME)

$(NAME): $(SOURCES)
	make libft
	make printf
	$(CC) $(SOURCES) printf/libftprintf.a libft/libft.a $(FLAGS) -o $(NAME)

clean:
	@echo Cleaning...
	make clean -C libft
	make clean -C printf

fclean: clean
	@echo fCleaning...
	make fclean -C libft
	make fclean -C printf
	rm -f $(NAME)

re : fclean all

printf:
	@echo Compiling Printf...
	make -C printf/

libft:
	@echo Compiling Libft...
	make -C libft/

.PHONY: all clean fclean re printf libft
.SILENT: