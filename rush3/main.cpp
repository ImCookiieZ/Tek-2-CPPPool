#include <iostream>
#include "src/graphical/ncurses/mainWindow.hpp"
int mainSFML(bool style);

int main(int ac, char **av)
{
    if (ac < 2)
        return 84;
    if (std::string(av[1]) == "-n")
    {
        mainNcurses();
    }
    else if (std::string(av[1]) == "-g")
    {
        if (ac == 3)
        {
            if (std::string(av[2]) == "-s")
                mainSFML(true);
        }
        else
            {
                mainSFML(false);
            }
    }

    return 0;
}
