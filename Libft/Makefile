# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 17:51:13 by mfanelli          #+#    #+#              #
#    Updated: 2024/11/28 17:37:59 by mfanelli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_split.c

BONUS_SRC = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
ft_lstdelone ft_lstclear ft_lstiter ft_lstmap 

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

$(NAME) : $(OBJECTS)
	@echo "Compiling $(NAME)"
	ar -rcs $(NAME) $(OBJECTS)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<
	
clean :
	rm -f $(OBJECTS)
fclean : clean
	rm -f $(NAME)

bonus: $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
	ranlib $(NAME)

all : $(NAME)
re : fclean all

.PHONY: all clean fclean bonus re
.SILENT: