# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 16:20:19 by mfanelli          #+#    #+#              #
#    Updated: 2025/01/20 11:56:41 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES = main.c so_long_utils.c error_map.c check_map.c moves.c path_finder.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g -Ilibft -Iprintf
MINILBX = -Lminilibx-linux -lmlx -Llibft -Lprintf -lXext -lX11
OBJ = $(SOURCES:.c=.o)

all :
	make libft
	make printf
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
	@./$(NAME) maps/mapboh.ber

clean:
	@echo Cleaning...
	@make clean -C libft
	@make clean -C printf
	@rm -f $(OBJ)

fclean: clean
	@echo fcking Cleaning...
	@make fclean -C libft
	@make fclean -C printf
	@rm -f $(NAME)

printf:
	@echo Compiling Printf...
	@make -C printf/

libft:
	@echo Compiling Libft
	@make -C libft/

norminette:
	@norminette check_map.c
	@norminette error_map.c
	@norminette main.c
	@norminette moves.c
	@norminette path_finder.c
	@norminette so_long_utils.c
	norminette so_long.h

.PHONY: all exe clean fclean printf libft norminette
.SILENT: