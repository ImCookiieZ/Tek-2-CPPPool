/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_DESERIALIZE_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_DESERIALIZE_HPP

size_t find_last(std::string const &src, std::string const &toSearch);
Toy *createToy(std::ifstream *file, const std::string& type);
Wrap *createWrap(std::ifstream *file, const std::string& type);
Object *createObject(std::ifstream *file, const std::string& type);
Object *createObject(std::ifstream *file);
Object *deserialize(const std::string& filepath);
void errorHandlingOnFiles(const std::string &filepath, std::string &line,
                          std::ifstream &file);
void wrap(Wrap *obj);

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_DESERIALIZE_HPP
