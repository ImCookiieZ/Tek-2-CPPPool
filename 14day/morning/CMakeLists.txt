cmake_minimum_required(VERSION 3.16)
project(morning)

set(CMAKE_CXX_STANDARD 14)

add_executable(morning main.cpp
        ex00/Fruit.cpp ex00/Fruit.hpp ex00/Lemon.cpp ex00/Lemon.hpp ex00/Banana.cpp ex00/Banana.hpp
        ex00/FruitBox.cpp ex00/FruitBox.hpp ex00/FruitNode.hpp
        ex01/Fruit.cpp ex01/Fruit.hpp ex01/Lemon.cpp ex01/Lemon.hpp ex01/Banana.cpp ex01/Banana.hpp
        ex01/FruitBox.cpp ex01/FruitBox.hpp ex01/FruitNode.hpp
        ex01/Lime.cpp ex01/Lime.hpp ex01/LittleHand.cpp ex01/LittleHand.hpp
        ex02/Fruit.cpp ex02/Fruit.hpp ex02/Lemon.cpp ex02/Lemon.hpp ex02/Banana.cpp ex02/Banana.hpp
        ex02/FruitBox.cpp ex02/FruitBox.hpp ex02/FruitNode.hpp
        ex02/Lime.cpp ex02/Lime.hpp ex02/LittleHand.cpp ex02/LittleHand.hpp
        ex02/Coconut.cpp ex02/Coconut.hpp
        ex03/Fruit.cpp ex03/Fruit.hpp ex03/Lemon.cpp ex03/Lemon.hpp ex03/Banana.cpp ex03/Banana.hpp
        ex03/FruitBox.cpp ex03/FruitBox.hpp ex03/FruitNode.hpp
        ex03/Lime.cpp ex03/Lime.hpp ex03/LittleHand.cpp ex03/LittleHand.hpp
        ex03/Coconut.cpp ex03/Coconut.hpp
        ex03/Mixer.cpp ex03/Mixer.hpp ex03/MixerBase.hpp
        )