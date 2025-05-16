NAME = megaphone

SOURCES = megaphone.cpp
OBJ = $(SOURCES:.cpp=.o)

CC = c++
FLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) : $(OBJ) $(SOURCES)
		@echo Compiling...
		$(CC) $(OBJ) $(FLAGS) -o $(NAME)

clean :
		@echo Cleaning...
		rm $(OBJ)

fclean : clean
		@echo fCleaning...
		rm $(NAME)

re : make fclean all

.PHONY: all clean fclean re
.SILENT: