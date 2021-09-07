/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** MutantStack.cpp
*/

#include "MutantStack.hpp"


//template<typename T, typename Container>
//auto MutantStack<T, Container>::begin()
//{
//    return std::begin(c);
//}
//
//template<typename T, typename Container>
//auto MutantStack<T, Container>::end()
//{
//    return std::end(c);
//}
//
//template<typename T, typename Container>
//MutantStack<T, Container>::iterator::iterator(const std::stack<T> &std, size_t size) : _tmpAfter(std), _size
//(size), _curIndex(0)
//{
//}
//
//template<typename T, typename Container>
//MutantStack<T, Container>::iterator::iterator(const std::stack<T> &std, size_t index, size_t size) :
//_tmpBefore(std), _size(size), _curIndex(index)
//{
//}
//
////template<typename T>
////typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator++()
////{
////    _curIndex++;
////    _tmpBefore.push(curVal);
////    _curIndex = _tmpAfter.top();
////    _tmpAfter.pop();
////    return *this;
////}
//
////template<typename T>
////typename MutantStack<T>::iterator &MutantStack<T>::iterator::operator--()
////{
////    _curIndex--;
////    _tmpAfter.push(curVal);
////    _curIndex = _tmpBefore.top();
////    _tmpBefore.pop();
////    return *this;
////}
//
//template<typename T, typename Container>
//T &MutantStack<T, Container>::iterator::operator*()
//{
//    return curVal;
//}
//
//template<typename T, typename Container>
//bool MutantStack<T, Container>::iterator::operator==(const MutantStack<T, Container>::iterator &rhs) const
//{
//    return rhs._curIndex == _curIndex;
//}
//
//template<typename T, typename Container>
//bool MutantStack<T, Container>::iterator::operator!=(const MutantStack<T, Container>::iterator &rhs) const
//{
//    return rhs._curIndex != _curIndex;
//}
//
//template<typename T>
//typename MutantStack<T>::iterator MutantStack<T>::begin()
//{
//    return MutantStack::iterator(_stack, _stack.size());
//}
//
//template<typename T>
//typename MutantStack<T>::iterator MutantStack<T>::end()
//{
//    return MutantStack::iterator(_stack, _stack.size(), _stack.size());
//}
//
//template<typename T>
//void MutantStack<T>::push(const T &add)
//{
//    _stack.push(add);
//}
//
//template<typename T>
//void MutantStack<T>::pop()
//{
//    _stack.pop();
//}
//
//template<typename T>
//size_t MutantStack<T>::size() const
//{
//    return _stack.size();
//}
//
//template<typename T>
//bool MutantStack<T>::empty() const
//{
//    return _stack.empty();
//}
//
//template<typename T>
//T &MutantStack<T>::top()
//{
//    return _stack.top();
//}
//template<typename T, typename Container>
//MutantStack<T, Container>::iterator::iterator(const std::stack<T> &std, size_t size)
//{
//}
//template<typename T, typename Container>
//MutantStack<T, Container>::iterator::iterator(const std::stack<T> &std, size_t size) : _tmpAfter
//(std), _size
//(size), _curIndex(0)
//{
//}
//
//template<typename T, typename Container>
//MutantStack<T, Container>::iterator::iterator(const std::stack<T> &std, size_t index, size_t size) :
//    _tmpBefore(std), _size(size), _curIndex(index)
//{
//}
//
//template<typename T, typename Container>
//typename MutantStack<T, Container>::iterator &MutantStack<T, Container>::iterator::operator++()
//{
//    _curIndex++;
//        _tmpBefore.push(curVal);
//        _curIndex = _tmpAfter.top();
//        _tmpAfter.pop();
//        return *this;
//}
//
//template<typename T, typename Container>
//typename MutantStack<T, Container>::iterator &MutantStack<T, Container>::iterator::operator--()
//{
//    _curIndex--;
//        _tmpAfter.push(curVal);
//        _curIndex = _tmpBefore.top();
//        _tmpBefore.pop();
//        return *this;
//}
//
//template<typename T, typename Container>
//bool MutantStack<T, Container>::iterator::operator==(const iterator &rhs) const
//{
//        return rhs._curIndex == _curIndex;
//}
//
//template<typename T, typename Container>
//bool MutantStack<T, Container>::iterator::operator!=(const iterator &rhs) const
//{
//    return rhs._curIndex != _curIndex;
//}
//
//template<typename T, typename Container>
//T &MutantStack<T, Container>::iterator::operator*()
//{
//    return curVal;
//}
//
//template<typename T, typename Container>
//typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
//{
//    return MutantStack::iterator(this->c, this->size());
//}
//
//template<typename T, typename Container>
//typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
//{
//    return MutantStack::iterator(this->c, this->size(), this->size());
//}
