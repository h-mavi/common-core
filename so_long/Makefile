NAME = a

LIBFT = ./libft
PRINTF = ./printf

SOURCES = window.c

CC = cc
FLAGS = -Wall -Wextra -Werror -g
#-Wall -Wextra -Werror -g -Ilibft -Iprintf
MINILBX = -Lminilibx-linux -lmlx -lXext -lX11
#-Lminilibx-linux -lmlx -Llibft -Lprintf -lftprintf -lft -lXext -lX11

OBJ = $(SOURCES:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(MINILBX)

%.o: %.c
	@echo Compiling $<...
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@echo Cleaning...
	@rm -f $(OBJ) $(NAME)
