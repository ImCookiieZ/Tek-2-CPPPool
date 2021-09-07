/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** Picture.cpp
*/

#include "Picture.hpp"

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream stream(file);
    if (!stream)
    {
        data = "ERROR";
        return false;
    }
    std::stringstream strStream;
    strStream << stream.rdbuf();
    if (!strStream)
    {
        data = "ERROR";
        return false;
    }
    data = strStream.str();
    return true;
}

Picture::Picture(const std::string file)
{
    getPictureFromFile(file);
}

Picture::Picture(Picture const &pic)
{
    data = std::string(pic.data);
}

Picture & Picture::operator=(Picture const &pic)
{
    data = std::string(pic.data);
    return *this;
}