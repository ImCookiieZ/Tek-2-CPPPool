/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD06_karl_erik_stoerzel
** File description:
** ex00.cpp
*/

#include <iostream>
#include <fstream>

void my_cat(char *path)
{
    char c = 0;
    std::ifstream file(path);
    if (file)
        while (file.get(c))
            std::cout << c;
    else
        std::cerr << "my_cat: " << path << ": No such file or directory" << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 2)
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    else
        for (int i = 1; i < ac; i++)
            my_cat(av[i]);
    return (0);
}