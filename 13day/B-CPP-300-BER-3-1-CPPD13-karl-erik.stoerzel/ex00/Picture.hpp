/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD13_karl_erik_stoerzel
** File description:
** Picture.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_PICTURE_HPP
#define B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_PICTURE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
class Picture
{
public:
    std::string data = "";
    bool getPictureFromFile(const std::string &file);
    explicit Picture(const std::string file);
    Picture() = default;
//    std::string getData();
};

#endif //B_CPP_300_BER_3_1_CPPD13_KARL_ERIK_STOERZEL_PICTURE_HPP
