/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** ToyStory.cpp
*/

#include "ToyStory.hpp"

bool ToyStory::tellMeAStory(std::string filepath, Toy toy1, func func1, Toy toy2, func func2)
{
    bool t1 = true;
    std::string line;
    std::ifstream file(filepath);
    if (!file)
    {
        std::cout << "Bad Story" << std::endl;
        return false;
    }
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    int line_counter = 0;
    while(getline(file, line))
    {
        if (line.find("picture:") == 0)
        {
            if (t1)
            {
                if (!toy1.setAscii(line.substr(8)))
                {
                    std::cout << toy1.getLastError().where() << ": " << toy1.getLastError().what
                        () << std::endl;
                    return false;
                }
                std::cout << toy1.getAscii() << std::endl;
            }
            else
            {
                if (!toy2.setAscii(line.substr(8)))
                {
                    std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what
                        () << std::endl;
                    return false;
                }
                std::cout << toy2.getAscii() << std::endl;
            }
        }
        else
        {
            if (t1)
            {
                if (!(toy1.*func1)(line))
                {
                    std::cout << toy1.getLastError().where() << ": " << toy1.getLastError().what
                    () << std::endl;
                    return false;
                }
            }
            else
            {
                if (!(toy2.*func2)(line))
                {
                    std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what
                        () << std::endl;
                    return false;
                }
            }
        }
        t1 = !t1;
        line_counter++;
    }
    return true;
}
//
//std::string ToyStory::getRestOfFile(std::ifstream file, int line)
//{
//    std::stringstream stream;
//    stream << file.rdbuf();
//    std::string ret(stream.str());
//    int pos = 0;
//
//    for (int i = 0; i < line; i++)
//        ret = ret.substr(ret.find('\n'));
//    ret = ret.substr(8);
//    return ret;
//}
