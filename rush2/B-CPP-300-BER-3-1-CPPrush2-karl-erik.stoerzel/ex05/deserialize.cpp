/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include <fstream>
#include "SantaClaus.hpp"

void errorHandlingOnFiles(const std::string &filepath, std::string &line, std::ifstream &file);
Object *createObject(std::ifstream *file);

int find_last(std::string const &src, std::string const &toSearch)
{
    int i = src.find(toSearch);
    int j = -1;
    while (i != std::string::npos && i >= 0)
    {
        j = i;
        i = src.find(toSearch, j + 1);
    }
    return j;
}

Toy *createToy(std::ifstream *file, const std::string& type)
{
    Toy *tmp;
    std::string sepBegin = "<Name>";
    std::string sepEnd = "</Name>";
    std::string line;
    int pos = 0;
    int endpos = 0;
    std::string name;
    if (!getline(*file, line))
    {
        std::cerr << "no valid xml 3" << std::endl;
        return nullptr;
    }
    pos = line.find(sepBegin);
    endpos = find_last(line, sepEnd);
    if (pos == std::string::npos || endpos == std::string::npos || endpos < pos)
    {
        name = "";
    }
    else
        name = line.substr(pos + sepBegin.length(), endpos - pos - sepBegin.length());
    if (type == "LittlePony")
        tmp = new LittlePony(name);
    else
        tmp = new Teddy(name);
    return tmp;
}

Wrap *createWrap(std::ifstream *file, const std::string& type)
{
    Wrap *tmp;
    int pos = 0;
    int endpos = 0;
    std::string sepBegin = "<Content>";
    std::string sepEnd = "</Content>";
    std::string line;
    std::string typeContent;

    if (type == "Wrap")
        tmp = new Wrap();
    else if (type == "GiftPaper")
        tmp = new GiftPaper();
    else
        tmp = new Box();
    if (!getline(*file, line))
    {
        std::cerr << "no valid xml 2" << std::endl;
        return nullptr;
    }
    tmp->closeMe();
    pos = line.find(sepBegin);
    endpos = find_last(line, sepEnd);
    if (pos == std::string::npos || (endpos > 0 && endpos < pos))
    {
        std::cerr << "no valid xml in create wrap 1 " << line << std::endl;
        return nullptr;
    }
    else if (endpos < 0)
    {
        if (!getline(*file, line))
        {
            std::cerr << "no valid xml in create wrap " << line << std::endl;
            return nullptr;
        }
        if (line.find("<Object>") != std::string::npos)
            tmp->setContent(createObject(file));
        return tmp;
    }
    typeContent = line.substr(pos + sepBegin.length(), endpos - pos - sepBegin.length());
    if (!typeContent.empty())
    {
        std::cerr << "no valid xml in create wrap " << line << std::endl;
        return nullptr;
    }
    return tmp;
}

Object *createObject(std::ifstream *file, const std::string& type)
{
    auto obj = new Object();
    return obj;
}

Object *createObject(std::ifstream *file)
{
    std::string sepBegin = "<Type>";
    std::string sepEnd = "</Type>";
    std::string line;
    int pos = 0;
    int endpos = 0;
    std::string type;

    if (!getline(*file, line))
    {
        std::cerr << "no valid xml" << std::endl;
        return nullptr;
    }
    pos = line.find(sepBegin);
    endpos = find_last(line, sepEnd);
    if (pos == std::string::npos || endpos == std::string::npos || endpos < pos)
    {
        std::cerr << "no valid xml" << line << std::endl;
        return nullptr;
    }
    type = line.substr(pos + sepBegin.length(), endpos - pos - sepBegin.length());
    if (type == "LittlePony" || type == "Toy" || type == "Teddy")
        return createToy(file, type);
    else if (type == "Box" || type == "GiftPaper" || type == "Wrap")
        return createWrap(file, type);
    else if (type == "Object")
        return createObject(file, type);
    else
    {
        std::cerr << "no valid xml in create object " << type <<  std::endl;
        return nullptr;
    }
}

Object *deserialize(const std::string& filepath)
{
    Object *obj;
    int pos = 0;
    std::string line;
    std::ifstream file(filepath);
    errorHandlingOnFiles(filepath, line, file);
    if (getline(file, line))
    {
        pos = line.find("<Object>", 0);
        if (pos != std::string::npos)
        {
            obj = createObject(&file);
            std::cout << *obj;
            return obj;
        }
    }
    std::cerr << "no valid xml no getline" << std::endl;
    return nullptr;
}

void errorHandlingOnFiles(const std::string &filepath, std::string &line,
std::ifstream &file)
{
    if (!file)
    {
        std::cerr << filepath << "No such File found" << std::endl;
    }
    if (!getline(file, line))
    {
        std::cerr << "No XML Content" << std::endl;
    }
    if (line != R"(<?xml version="1.0" encoding="ISO-8859-1" ?>)")
    {
        std::cerr << "No valid XML for this Program!:" << std::endl;
        std::cerr << line << std::endl;
    }
}

void wrap(Wrap *obj)
{
    obj->openMe();
    Object *tmp = obj->TakeContent(true);
    std::string type;
    if (!tmp)
    {
        std::cerr << "HOHOHO why is this wrap empty?..." << std::endl;
        return;
    }
    type = tmp->getType();
    if (type == "Wrap" || type == "Box" || type == "GiftPaper")
        wrap(dynamic_cast<Wrap*>(tmp));
    else if (type == "Toy" || type == "LittlePony" || type == "Teddy")
    {
        tmp->isTaken();
        std::cout << "Perfect, this " << tmp->getType() << " is a nice gift.";
        std::string name = dynamic_cast<Toy *>(tmp)->getName();
        if (!name.empty())
            std::cout <<  " I will name this toy \"" << name << "\"";
        std::cout << std::endl;
    }
    obj->wrapMeThat(*tmp, true);
    obj->closeMe();
}