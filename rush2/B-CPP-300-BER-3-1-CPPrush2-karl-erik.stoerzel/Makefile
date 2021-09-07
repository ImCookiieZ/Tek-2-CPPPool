##
## EPITECH PROJECT, 2021
## test
## File description:
## test
##

SRC			=		ex00/LittlePony.cpp\
					ex00/Object.cpp\
					ex00/Teddy.cpp\
					ex00/Toy.cpp\
					ex01/Box.cpp\
					ex01/GiftPaper.cpp\
					ex01/Wrap.cpp\
					ex02/PapaXmasConveyorBelt.cpp\
					ex02/PapaXmasTable.cpp\
					ex03/PapaXmasElf.cpp\
					ex04/ConveyorBeltRand.cpp\
					ex04/TableRand.cpp\
					general.cpp\
					main_base.cpp

SRCSANTA	=		ex00/LittlePony.cpp\
					ex00/Object.cpp\
					ex00/Teddy.cpp\
					ex00/Toy.cpp\
					ex01/Box.cpp\
					ex01/GiftPaper.cpp\
					ex01/Wrap.cpp\
					ex02/PapaXmasConveyorBelt.cpp\
					ex02/PapaXmasTable.cpp\
					ex03/PapaXmasElf.cpp\
					ex04/ConveyorBeltRand.cpp\
					ex04/TableRand.cpp\
					general.cpp\
					ex05/SantaClaus.cpp\
					ex05/deserialize.cpp\
					ex06/WarpClient.cpp\
					ex06/WarpServer.cpp

OBJ			=		$(SRC:.cpp=.o)

OBJSANTA	=		$(SRCSANTA:.cpp=.o)


CFLAGS += -g -W -Wall -Wextra -Werror -std=gnu11

NAME		=	test

NAMESANTA		=	santa

RM			=		rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(OBJ) -Wall -Wextra -Werror -g

$(NAMESANTA): $(OBJSANTA)
			g++ -o $(NAMESANTA) $(OBJSANTA) -Wall -Wextra -Werror -g

santa:	 $(NAMESANTA)

clean:	$(OBJ) $(OBJSANTA)
	rm $(OBJ) ex05/SantaClaus.o ex05/deserialize.o ex06/WarpClient.o ex06/WarpServer.o

fclean: clean
		$(RM) $(NAME) $(NAMESANTA)

re: fclean all

.PHONY: all clean flean re