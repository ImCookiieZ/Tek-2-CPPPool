/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD15_karl_erik_stoerzel
** File description:
** ex05.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX05_HPP
#define B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX05_HPP

#include <iostream>

template<typename T>
class array
{
    size_t _size;
    T *_ar = nullptr;
    void freeAr();
public:
    explicit array(size_t size);
    array();
    array(const array<T> &from);
    ~array();

    size_t size() const;
    void dump() const;

    template<typename U>
    array<U> convertTo(U(*convert)(const T &var)) const;

    array<T> &operator=(array<T> const &from);
    T &operator[](size_t index) const;
    T &operator[](size_t index);
};

template<typename T>
array<T>::array(const size_t size)
{
    _ar = new T[size];
    _size = size;
}

template<typename T>
array<T>::array()
{
    _ar = nullptr;
    _size = 0;
}

template<typename T>
array<T>::array(const array<T> &from)
{
    _size = from._size;
    _ar = new T[_size];
    for (size_t i = 0; i < _size; i++)
        _ar[i] = from._ar[i];
}

template<typename T>
array<T> &array<T>::operator=(array<T> const &from)
{
    freeAr();
    _size = from._size;
    _ar = new T[_size];
    for (size_t i = 0; i < _size; i++)
        _ar[i] = from._ar[i];
    return *this;
}

template<typename T>
T &array<T>::operator[](size_t index) const
{
    if (index >= _size)
    {
        std::exception ex;
        throw (ex);
    }
    return _ar[index];
}

template<typename T>
T &array<T>::operator[](size_t index)
{
    if (index >= _size)
    {
        int tmp_size = _size;
        T* tmp = _ar;
        _size = index + 1;
        _ar = new T[_size];
        for (size_t i = 0; i < tmp_size; i++)
            _ar[i] = tmp[i];
        delete[] tmp;
    }
    return _ar[index];
}

template<typename T>
array<T>::~array()
{
    freeAr();
}

template<typename T>
size_t array<T>::size() const
{
    return _size;
}

template<typename T>
void array<T>::dump() const
{
    std::cout << "[";
    for (size_t i = 0; i < _size; i++)
    {
        std::cout << _ar[i];
        if (i < _size - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

template<>
void array<bool>::dump() const
{
    std::cout << "[";
    for (size_t i = 0; i < _size; i++)
    {
        std::cout << (_ar[i] ? "true" : "false");
        if (i < _size - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

template<typename T>
template<typename U>
array<U> array<T>::convertTo(U (*convertFunc)(const T &)) const
{
    if (!convertFunc)
        return array<U>(_size);
    array<U> ret(_size);
    for (size_t i = 0; i < _size; i++)
        ret[i] = (*convertFunc)(_ar[i]);
    return ret;
}

template<typename T>
void array<T>::freeAr()
{
    if (!_ar)
        return;
    delete[] _ar;
    _ar = nullptr;
}

#endif //B_CPP_300_BER_3_1_CPPD15_KARL_ERIK_STOERZEL_EX05_HPP
