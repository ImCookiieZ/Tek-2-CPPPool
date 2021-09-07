/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel
** File description:
** BF_Translator.cpp
*/

#include "BF_Translator.hpp"

void BF_Translator::writeIncludes()
{
    *_out << "#include <string.h>" << std::endl;
    *_out << "#include <stdlib.h>" << std::endl;
    *_out << "#include <unistd.h>" << std::endl;
}

int BF_Translator::translate(const std::string &in, const std::string &out)
{
    try
    {
        _in = new std::ifstream(in.c_str());
        _out = new std::ofstream(out.c_str());
        if (!_in || !_out)
            throw std::exception();
        command_t command;
        writeIncludes();
        startMain();
        createVariables();
        while(!_in->eof())
        {
            char c = _in->get();
            if (c == ' ' || c == -1 || c == '\n')
                continue;
            command = _allCommands[c];
            if (command)
                (this->*command)();
            else
                throw std::exception();
        }
        endMain();
    } catch (std::exception &exception)
    {
        return (84);
    }
    return (0);
}

BF_Translator::~BF_Translator()
{
    delete _in;
    delete _out;
}

void BF_Translator::startMain()
{
    if (_mainStarted)
        return;
    _mainStarted = true;
    *_out << std::endl << "int main()" << std::endl;
    *_out << "{" << std::endl;
    _deep++;
}

void BF_Translator::endMain()
{
//    if (_deep != 1)
//        throw std::exception();
    if (!_mainStarted)
        return;
    *_out << "\treturn 0;" << std::endl;
    *_out << "}";
}

void BF_Translator::createVariables()
{
    *_out << "\tchar *" << _memoryName << " = malloc(" << _memorySize << " + 1);" << std::endl;
    *_out << "\tmemset(" << _memoryName << ", 0, " << _memorySize << " + 1);" << std::endl;
    *_out << "\tunsigned int " << _pointerName << " = 0;" << std::endl;

}

BF_Translator::BF_Translator()
{
    _allCommands['+'] = &BF_Translator::incrementPointedByte;
    _allCommands['-'] = &BF_Translator::decrementPointedByte;
    _allCommands['>'] = &BF_Translator::movePointerForward;
    _allCommands['<'] = &BF_Translator::movePointerBackward;
    _allCommands['.'] = &BF_Translator::printPointedByte;
    _allCommands[','] = &BF_Translator::readInputIntoPointedByte;
    _allCommands['['] = &BF_Translator::bracketsOn;
    _allCommands[']'] = &BF_Translator::bracketsOff;
}

void BF_Translator::incrementPointedByte()
{
    for (unsigned int i = 0; i < _deep; i++)
        *_out << "\t";
    *_out << _memoryName << "[" << _pointerName << "]++;" << std::endl;
}

void BF_Translator::decrementPointedByte()
{
    for (unsigned int i = 0; i < _deep; i++)
        *_out << "\t";
    *_out << _memoryName << "[" << _pointerName << "]--;" << std::endl;
}

void BF_Translator::movePointerForward()
{
    for (unsigned int i = 0; i < _deep; i++)
        *_out << "\t";
    *_out << _pointerName << "++;" << std::endl;
}

void BF_Translator::movePointerBackward()
{
    for (unsigned int i = 0; i < _deep; i++)
        *_out << "\t";
    *_out << _pointerName << "--;" << std::endl;
}

void BF_Translator::printPointedByte()
{
    for (unsigned int i = 0; i < _deep; i++)
        *_out << "\t";
    *_out << "write(1, &" << _memoryName << "[" << _pointerName << "], 1);" << std::endl;
}

void BF_Translator::readInputIntoPointedByte()
{
    for (unsigned int i = 0; i < _deep; i++)
        *_out << "\t";
    *_out << "read(0, &" << _memoryName << "[" << _pointerName << "], 1);" << std::endl;
}

void BF_Translator::bracketsOn()
{
    for (unsigned int i = 0; i < _deep; i++)
        *_out << "\t";
    *_out << "while (" << _memoryName << "[" << _pointerName << "])" << std::endl;
    for (unsigned int i = 0; i < _deep; i++)
        *_out << "\t";
    *_out << "{" << std::endl;
    _deep++;
}

void BF_Translator::bracketsOff()
{
    _deep--;
    for (unsigned int i = 0; i < _deep; i++)
        *_out << "\t";
    *_out << "}" << std::endl;
}
