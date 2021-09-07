/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD17_karl_erik_stoerzel
** File description:
** find.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_FIND_HPP
#define B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_FIND_HPP

#include <algorithm>

template<typename Container>
typename Container::iterator do_find(Container &container, int search)
{
    return std::find(container.begin(), container.end(), search);
}

#endif //B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_FIND_HPP
