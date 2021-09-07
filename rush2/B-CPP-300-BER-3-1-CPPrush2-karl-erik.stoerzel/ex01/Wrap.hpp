/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPrush2_karl_erik_stoerzel
** File description:
** Wrap.hpp
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_WRAP_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_WRAP_HPP

#include "../ex00/Object.hpp"

class Wrap : public Object
{
protected:
    Object *_content;
    bool _isOpen;
public:
    explicit Wrap(std::string type = "Wrap");
    static void wrapTalk() ;
    virtual void wrapMeThat(Object &objToWrap, bool santa);
    void closeMe();
    void openMe();
    virtual Object *TakeContent(bool santa);
    Object *getContent() const;
    void isTaken() const override ;
    bool isWrapped() const;
    ~Wrap() override;
    bool getOpen() const;
    void setContent(Object *content);
};

std::ostream &operator<<(std::ostream &ostream, Wrap const &wrap);

#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_WRAP_HPP
