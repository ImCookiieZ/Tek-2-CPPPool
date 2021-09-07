##
## EPITECH PROJECT, 2019
## Makefile
## File description
## 
##

SRC	= 	src/getSystemData/SystemGetter.cpp  \
		src/graphical/ncurses/mainWindow.cpp\
		src/SFML/SFGraphing/PieChartDataSet.cpp\
		src/SFML/SFGraphing/PlotDataSet.cpp\
		src/SFML/SFGraphing/SFPieChart.cpp\
		src/SFML/SFGraphing/SFPlot.cpp\
		src/SFML/main.cpp\
		src/SFML/MonitorDisplay.cpp\
		src/SFML/MonitorModule.cpp\
		src/CpuMhzInfo.cpp \
		src/CpuPercentage.cpp \
		src/Displays.cpp\
		src/NetworkData.cpp\
		src/RamInfos.cpp\
		src/SwapInfos.cpp\
		src/User.cpp\
		main.cpp


LIB =   -lncurses -lsfml-graphics -lsfml-window -lsfml-system
RM	=	rm -f

NAME	=   rush3

GCC	=	g++ -o

all:		$(NAME)

$(NAME):	$(SRC)
	$(GCC) $(NAME) $(SRC) $(LIB)

run: $(Name)
	./rush3 -n

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re