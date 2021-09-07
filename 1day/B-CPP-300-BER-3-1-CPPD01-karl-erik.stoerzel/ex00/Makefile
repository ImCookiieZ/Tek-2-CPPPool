##
## EPITECH PROJECT, 2021
## ex01
## File description:
## test
##

SRC			=		z.c

OBJ			=		$(SRC:.c=.o)

CFLAGS = -I include/

CFLAGS += -g -W -Wall -Wextra -std=gnu11

NAME		=		z

RM		=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)

clean:	$(OBJ)
	rm $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re