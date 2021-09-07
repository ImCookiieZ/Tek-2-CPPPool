/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** BF_Translator.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_BF_TRANSLATOR_HPP
#define B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_BF_TRANSLATOR_HPP

#include <string>
#include <fstream>
#include <map>

class BF_Translator
{
private:
    using command_t = void (BF_Translator::*)();
    std::string const _memorySize = "60 * 1024";
    std::string const _memoryName = "allocatedMemory";
    std::string const _pointerName = "pointerToMemory";
    std::ofstream *_out = nullptr;
    std::ifstream *_in = nullptr;
    std::map<char, command_t> _allCommands;
    bool _mainStarted = false;
    unsigned int _deep = 0;
    //main file writing
    void writeIncludes();
    void startMain();
    void endMain();
    void createVariables();

    //doableFunctions
    void incrementPointedByte();
    void decrementPointedByte();
    void movePointerForward();
    void movePointerBackward();
    void printPointedByte();
    void readInputIntoPointedByte();
    void bracketsOn();
    void bracketsOff();
public:
    BF_Translator();
    ~BF_Translator();
    int translate(const std::string &in, const std::string &out);
};

#endif //B_CPP_300_BER_3_1_CPPD16_KARL_ERIK_STOERZEL_BF_TRANSLATOR_HPP
