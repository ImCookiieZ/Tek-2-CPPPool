##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## for evalexpr
##

SRC		=   string_t_init_and_destroy.c\
			assign.c\
			append_s.c\
			at.c\
			clear.c\
			size.c\
			compare.c\
			copy.c\
			c_str.c\
			empty.c\
			find.c\
			insert.c\
			to_int.c\
			split_s.c\
			split_c.c\
			print.c\
			join.c\
			substr.c

OBJ		=	$(SRC:.c=.o)

NAME		=	libstring.a

SRC_MAIN    =	main.c $(SRC)

OBJ_MAIN    =   $(SRC_MAIN:.c=.o)

MAIN	    =	main

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc -o $(NAME) $(OBJ)

tests_run:	$(OBJ_TEST)
		gcc -o $(TEST) $(OBJ_TEST) -lcriterion
		./test_run

run:		$(OBJ_MAIN)
		gcc -o $(MAIN) $(OBJ_MAIN) -g3
		./main

clean:
	rm -f $(OBJ) $(OBJ_TEST) $(OBJ_MAIN)

fclean: clean
	rm -f $(NAME) $(MAIN) $(TEST)

re:	fclean all

.PHONY: all clean fclean re
