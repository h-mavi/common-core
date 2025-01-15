# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 16:20:19 by mfanelli          #+#    #+#              #
#    Updated: 2025/01/15 17:00:18 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = main.c so_long_utils.c error_map.c check_map.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft -Iprintf
MINILBX = -Lminilibx-linux -lmlx -Llibft -Lprintf -lXext -lX11
OBJ = $(SOURCES:.c=.o)

all :
	make libft
	make printf
	make minilbx
	make $(NAME)
	make exe

$(NAME): $(OBJ)
	@$(CC) $(OBJ) printf/libftprintf.a libft/libft.a $(FLAGS) $(MINILBX) -o $(NAME)

%.o: %.c
	@echo Compiling $<...
	@$(CC) $(FLAGS) -o $@ -c $<

exe : $(NAME)
	@echo Executing...
	@clear
	@./$(NAME) map.ber

clean:
	@echo Cleaning...
	@make clean -C libft
	@make clean -C printf
	@rm -f $(OBJ)

fclean:
	@echo fcking Cleaning...
	@make fclean -C libft
	@make fclean -C printf
	@rm -f $(NAME)

printf:
	@echo Compiling Printf...
	@make -C printf/

minilbx:
	@echo Compiling Minilibix
	@make -C minilibx-linux

libft:
	@echo Compiling Libft
	@make -C libft/

.PHONY: all exe clean fclean printf libft
.SILENT: