/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#ifndef B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_WARPSERVER_HPP
#define B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_WARPSERVER_HPP

#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "memory.h"

class WarpServer {
public:
    WarpServer(std::string address, int port);
    ~WarpServer();

    void setTimeout(int ms);
    std::string receive();
    void sendAddress() const;
    int sendMessage(const std::string &message);

private:
    std::string _address;
    struct sockaddr_in _saddress;
    int _port;
    int _sockFD;
};
#endif //B_CPP_300_BER_3_1_CPPRUSH2_KARL_ERIK_STOERZEL_WARPSERVER_HPP
