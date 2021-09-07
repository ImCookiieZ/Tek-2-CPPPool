/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** MutantStack.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_MUTANTSTACK_HPP
#define B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_MUTANTSTACK_HPP
#include <stack>
#include <deque>

//template<typename T>
//class MutantStack : public std::stack<T>
//{
//private:
////    using std::stack<T, Container>::c;
////    std::stack<T> _stack;
//public:
//    using iterator = typename std::deque<T>::reverse_iterator;
//    std::reverse_iterator<T> iterator;
//    class iterator
//    {
//    private:
//        size_t _size;
//        size_t _curIndex;
//        std::stack<T> _tmpBefore;
//        std::stack<T> _tmpAfter;
//        T curVal;
//    public:
//        explicit iterator(std::stack<T> const &std, size_t size);
//        explicit iterator(std::stack<T> const &std, size_t index, size_t size);
//        iterator& operator++();
//        iterator& operator--();
//        bool operator==(iterator const &rhs) const;
//        bool operator!=(iterator const &rhs) const;
//        T &operator*();
//    };
//    iterator begin()
//{
//    iterator::rbegin();
//}
//    iterator end()
//    {
//        iterator::rend();
//    }
//    void push(const T& add) ;
//    void pop();
//    size_t size() const;
//    bool empty() const;
//    T &top();
//};
template<typename T>
class MutantStack : public std::stack<T>
{
public:
    class iterator
    {
    private:
        MutantStack *_container;
        int _index;
    public:
        iterator() : _index(0){ _container = nullptr;}
        iterator(iterator const &rhs) : _index(rhs._index)
        {
            _container = new MutantStack<T>(*rhs._container);
        }
        iterator(MutantStack &m_stack, size_t index) : _index(index)
        {
            _container = new MutantStack<T>(m_stack);
        }
        iterator &operator++()
        {
            if (_index >= 0)
                _index--;
            return *this;
        }
        iterator &operator--()
        {
            if (_index < _container->size())
                _index++;
            return *this;
        }
        bool operator==(iterator const &rhs)
        {
            return rhs._index == _index;
        }
        bool operator!=(iterator const &rhs)
        {
            return rhs._index != _index;
        }
        T &operator*()
        {
            return _container->c[_index];
        }
        T &operator->()
        {
            return _container->c[_index];
        }
        iterator &operator=(iterator const &rhs)
        {
            _container = rhs._container;
            _index = rhs._index;
            return *this;
        }
    };
    iterator begin()
    {
        return iterator(*this, this->size() - 1);
    }
    iterator end()
    {
        return iterator(*this, -1);
    }
};


#endif //B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_MUTANTSTACK_HPP
