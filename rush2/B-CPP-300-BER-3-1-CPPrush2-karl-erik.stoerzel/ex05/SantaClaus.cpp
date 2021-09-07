/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** SantaClaus.cpp
*/

#include <fstream>
#include "SantaClaus.hpp"
#include "deserialize.hpp"
#include "../ex06/WarpClient.hpp"

int warpMachine(int ac, char **av, int index)
{
    if (index + 1 == ac)
        return (84);
    WarpServer sock(av[index + 1], 1337);
    sock.sendAddress();
    while (true) {
        std::string answer = sock.receive();
        if (deserialize(answer) == nullptr)
            return (84);
    }
}

void checkFiles(char **av, int i)
{
    Object *tmp;
    std::string type;
    tmp = deserialize(std::string(av[i]));
    if (!tmp)
    {
        std::cerr << std::endl;
        return;
    }
    type = tmp->getType();
    if (type != "GiftPaper")
    {
        std::cerr << "EEEELLLFF why is this " << type << " not wrapped into a gift paper?" <<
                  std::endl;
    }
    if (type == "Wrap" || type == "Box" || type == "GiftPaper")
        wrap(dynamic_cast<Wrap*>(tmp));
    else if (type == "Toy" || type == "LittlePony" || type == "Teddy")
    {
        tmp->isTaken();
        std::cerr << "Whyyyy is this gift not wrapped?..." << std::endl;
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    for (int i = 1; i < ac; i += 1)
        if (!strcmp(av[i], "-w") && i < ac - 1)
            return(warpMachine(ac, av, i));
    for (int i = 1; i < ac; i += 1)
        checkFiles(av, i);
    return (0);
}