/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** Parser.cpp
*/

#include "Parser.hpp"
#include <iostream>
void Parser::reset()
{
    while (!_operands.empty())
        _operands.pop();
    while (!_operators.empty())
        _operators.pop();
    _result = 0;
}

int Parser::result() const
{
    return _result;
}

void Parser::feed(const std::string &task)
{
//    operation = task;

    parse(task);
//    operation.clear();
}

Parser::Parser(const Parser &from) : _operands(from._operands), _operators(from._operators)
{
    _result = from._result;
}

int Parser::parse(std::string const &task)
{
    std::string tmpnum;
    const int max = task.size();
    for (int i = 0; i < max; i++)
    {
        tmpnum.clear();
        if (task[i] >= '0' && task[i] <= '9')
        {
            while (task[i] >= '0' && task[i] <= '9')
            {
                tmpnum += task[i];
                i++;
            }
            i--;
            _operands.push(atoi(tmpnum.c_str()));
        }
        else if (task[i] == '('
        || task[i] == '+' || task[i] == '-'
        || task[i] == '*' || task[i] == '/' || task[i] == '%')
        {
            _operators.push(task[i]);
        }
        else if (task[i] == ')')
        {
            while (_operators.top() != '(')
            {
                calculate();
            }
            _operators.pop();
        }
    }
    while (!_operators.empty())
        calculate();
    _result += _operands.top();
    while (!_operators.empty())
        _operators.pop();
    return 0;
}

void Parser::calculate()
{
    int right = _operands.top();
    _operands.pop();
    int left = _operands.top();
    _operands.pop();
    switch (_operators.top())
    {
        case '+':
            _operands.push(left + right);
            break;
        case '-':
            _operands.push(left - right);
            break;
        case '*':
            _operands.push(left * right);
            break;
        case '/':
            _operands.push(left / right);
            break;
        case '%':
            _operands.push(left % right);
            break;
    }
    _operators.pop();
}
