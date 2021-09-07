//
// Created by hasan on 1/23/21.
//

#ifndef B_CPP_300_BER_3_1_CPPRUSH3_KARL_ERIK_STOERZEL_USER_HPP
#define B_CPP_300_BER_3_1_CPPRUSH3_KARL_ERIK_STOERZEL_USER_HPP

#include <string>
#include "Displays.hpp"

class User : public Displays
{
public:
    User()
    {
        Chart = NONE;
        SetHostname();
        SetUserName();
    }
    ~User() = default;
    void SetHostname();
    void SetUserName();
    std::string GetHostname() const;
    std::string GetUsername() const;
    std::string GetName() const override{return "User:";};
    std::string GetString1() const override;
    std::string GetString2() const override;
    std::string GetString3() const override;
    float GetActual() override;
    float GetMax() override;
private:
    std::string _hostName;
    std::string _userName;

};

#endif //B_CPP_300_BER_3_1_CPPRUSH3_KARL_ERIK_STOERZEL_USER_HPP
