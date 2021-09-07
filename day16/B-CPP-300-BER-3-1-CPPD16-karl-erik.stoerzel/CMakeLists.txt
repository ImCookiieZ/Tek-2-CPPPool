cmake_minimum_required(VERSION 3.16)
project(B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel)

set(CMAKE_CXX_STANDARD 14)

add_executable(B_CPP_300_BER_3_1_CPPD16_karl_erik_stoerzel main.cpp ex00/DomesticKoala.cpp
        ex00/DomesticKoala.hpp ex00/KoalaAction.hpp ex01/Event.cpp ex01/Event.hpp
        ex01/EventManager.cpp ex01/EventManager.hpp ex02/BF_Translator.cpp ex02/BF_Translator.hpp ex03/Ratatouille.cpp ex03/Ratatouille.hpp ex04/Parser.cpp ex04/Parser.hpp ex05/MutantStack.cpp ex05/MutantStack.hpp)