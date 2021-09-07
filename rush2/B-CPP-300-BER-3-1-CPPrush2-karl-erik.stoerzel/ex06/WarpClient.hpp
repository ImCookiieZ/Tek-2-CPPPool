/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_WARPCLIENT_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_WARPCLIENT_HPP
#include <vector>
#include <iostream>

#include <netdb.h>
#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "WarpServer.hpp"
#include <memory>
class WarpClient
{
public:
    WarpClient();
    ~WarpClient();

    int sendMessage(const std::string &message);
    void receiveAddr();
private:
    WarpServer *_warpServer;
    struct sockaddr_in _saddress;
    int _port;
    int _sockFD;
    std::vector<std::string> _addressList;
    std::string _listenerAddress;
};
#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_WARPCLIENT_HPP
