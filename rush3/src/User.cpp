//
// Created by hasan on 1/23/21.
//

#include "User.hpp"

#include <utility>
#include "getSystemData/SystemGetter.hpp"

void User::SetHostname() {
    _hostName = SystemGetter::GetHostname();
}

void User::SetUserName() {
    _userName = SystemGetter::GetUsername();
}

std::string User::GetHostname() const {
    return (_hostName);
}

std::string User::GetUsername() const {
    return (_userName);
}

float User::GetActual()
{
    return 0;
}

float User::GetMax()
{
    return 0;
}

std::string User::GetString3() const
{
    return SystemGetter::GetOperatingSystem() + " " + SystemGetter::GetKernelVersion();
}

std::string User::GetString1() const
{
    return SystemGetter::GetDateTime();
}

std::string User::GetString2() const
{
    return _userName + " " + _hostName;
}
