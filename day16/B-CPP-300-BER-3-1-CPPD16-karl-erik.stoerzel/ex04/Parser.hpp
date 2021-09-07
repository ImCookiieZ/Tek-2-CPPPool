/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** Parser.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_PARSER_HPP
#define B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_PARSER_HPP

#include <stack>
#include <string>

class Parser
{
private:
//    std::string operation;
    std::stack<char> _operators;
    std::stack<int> _operands;
    int _result = 0;
public:
    Parser() = default;
    Parser(const Parser &from);
    void feed(const std::string &task);
    int result() const;
    int parse(std::string const &task);
    void reset();

    void calculate();
};

#endif //B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_PARSER_HPP
