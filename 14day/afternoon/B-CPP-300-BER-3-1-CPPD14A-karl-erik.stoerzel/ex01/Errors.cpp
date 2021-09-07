/*
** EPITECH PROJECT, 2021
** B_CPP_300_BER_3_1_CPPD14A_karl_erik_stoerzel
** File description:
** Errors.cpp
*/

#include "Errors.hpp"

NasaError::NasaError(const std::string &message, const std::string &component)
{
    _message = message;
    _component = component;
}

std::string const &NasaError::getComponent() const
{
    return _component;
}

const char *NasaError::what() const noexcept
{
    return _message.c_str();
}

MissionCriticalError::MissionCriticalError(const std::string &message, const std::string &component)
    : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(const std::string &message, const std::string &component)
    : NasaError(message, component)
{
}

UserError::UserError(const std::string &message, const std::string &component) : NasaError(message,
                                                                                           component)
{
}

CommunicationError::CommunicationError(const std::string &message) : NasaError(message,
    "CommunicationDevice")
{
}
