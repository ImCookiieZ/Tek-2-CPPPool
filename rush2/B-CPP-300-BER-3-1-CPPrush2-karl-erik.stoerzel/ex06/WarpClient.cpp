/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "WarpClient.hpp"

WarpClient::WarpClient() : _warpServer(new WarpServer(_listenerAddress,_port)),
_port(4221) ,_listenerAddress("234.42.42.42")
{
    memset(&_saddress, 0, sizeof(struct sockaddr_in));
    _sockFD = socket(AF_INET, SOCK_DGRAM, 0);
    if (_sockFD <= 0) {
        std::cerr << "Couldn't initialize client socket" << std::endl;
        return;
    }
    _saddress.sin_family = AF_INET;
    _saddress.sin_port = htons(0);
    _saddress.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(_sockFD, (struct sockaddr *)&_saddress, sizeof(_saddress))) {
        std::cerr << "Couldn't bind client socket" << std::endl;
        close(_sockFD);
    }
}

WarpClient::~WarpClient()
{
    delete _warpServer;
    close(_sockFD);
}

void WarpClient::receiveAddr()
{
    _warpServer->setTimeout(50);
    std::string ret;
    while (!(ret = _warpServer->receive()).empty()) {
        std::vector<std::string>::iterator it;
        for (it = _addressList.begin(); it != _addressList.end(); it++) {
            if (*it == ret)
                return;
        }
        _addressList.push_back(ret);
    }
    _warpServer->setTimeout(0);
}

int WarpClient::sendMessage(const std::string &message)
{
    _saddress.sin_family = AF_INET;
    _saddress.sin_port = htons(1337);

    std::vector<std::string>::iterator it;
    for (it = _addressList.begin(); it != _addressList.end(); it++) {
        _saddress.sin_addr.s_addr = inet_addr((*it).c_str());
        if (sendto(_sockFD, message.c_str(), message.size(), 0,
                   (struct sockaddr *)&_saddress, sizeof(_saddress)) == -1)
            return (-1);
    }
    return (1);
}
