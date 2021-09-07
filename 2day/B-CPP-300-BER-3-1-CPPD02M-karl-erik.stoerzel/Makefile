##
## EPITECH PROJECT, 2021
## test
## File description:
## test
##

SRC			=		menger.c \
					drawing.c \
					bitmap_header.c \
					main.c

OBJ			=		$(SRC:.c=.o)

CFLAGS = -I include/

CFLAGS += -g -W -Wall -Wextra -Werror -std=gnu11

NAME		=		menger_face

RM			=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(SRC) -I .

clean:	$(OBJ)
	rm $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean flean re