/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD17_karl_erik_stoerzel
** File description:
** Container.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_CONTAINER_HPP
#define B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_CONTAINER_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template<typename T>
void aff(T const &value)
{
    std::cout << "Value: " << value << std::endl;
}

template<typename T>
void add(T &value)
{
    value++;
}

template<typename T, template<typename, typename> class Container>
class contain
{
private:
    Container<T, std::allocator<T>> _container;
public:
    void push(T const &data);
    void add()
    {
        std::for_each(_container.begin(), _container.end(), &::add<T>);
    }
    void aff()
    {
        std::for_each(_container.begin(), _container.end(), &::aff<T>);
    }
};

template<typename T, template<typename, typename> class Container>
void contain<T, Container>::push(const T &data)
{
    _container.push_back(data);
}

template<typename T>
void contain<T, std::stack<T, std::allocator<T>>>::push(const T &data)
{
    _container.push(data);
}

#endif //B_CPP_300_BER_3_1_CPPD17_KARL_ERIK_STOERZEL_CONTAINER_HPP
