##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for evalexpr
##

SRC		=   ex00.cpp

OBJ		=	$(SRC:.cpp=.o)

NAME		=	my_cat

CFLAGS += -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re:	fclean all

.PHONY: all clean fclean re
