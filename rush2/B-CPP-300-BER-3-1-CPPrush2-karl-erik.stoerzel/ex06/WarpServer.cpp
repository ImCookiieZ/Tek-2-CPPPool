/*
** EPITECH PROJECT, 2019
** FILE_NAME
** File description:
** FILE DESCRIPTION
*/

#include "WarpServer.hpp"

WarpServer::WarpServer(std::string addr, int port)
    : _address(addr), _port(port)
{
    struct ip_mreq imreq;
    int n = 1;

    _sockFD = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (_sockFD == -1) {
        std::cerr << "Could not create server socket" << std::endl;
        return;
    }
    setsockopt(_sockFD, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(n));
    memset(&_saddress, 0, sizeof(struct sockaddr_in));
    _saddress.sin_family = AF_INET;
    _saddress.sin_port = htons(_port);
    _saddress.sin_addr.s_addr = inet_addr(_address.c_str());
    memset(&imreq, 0, sizeof(struct ip_mreq));
    if (bind(_sockFD, (struct sockaddr *)&_saddress, sizeof(_saddress)) != 0) {
        std::cerr << "Could not connect" << std::endl;
        close(_sockFD);
        return;
    }
    imreq.imr_multiaddr.s_addr = inet_addr(_address.c_str());
    imreq.imr_interface.s_addr = INADDR_ANY;
    setsockopt(_sockFD, IPPROTO_IP, IP_ADD_MEMBERSHIP, &imreq,
               sizeof(struct ip_mreq));
}

WarpServer::~WarpServer()
{
    close(_sockFD);
}

void WarpServer::setTimeout(int ms)
{
    struct timeval tout;

    tout.tv_sec = ms / 1000;
    tout.tv_usec = (ms % 1000) * 1000;
    setsockopt(_sockFD, SOL_SOCKET, SO_RCVTIMEO, &tout, sizeof(tout));
}

void WarpServer::sendAddress() const
{
    struct sockaddr_in saddr;
    int sockFD;
    memset(&saddr, 0, sizeof(struct sockaddr_in));
    if ((sockFD = socket(AF_INET, SOCK_DGRAM, 0)) < 1) {
        std::cerr << "Couldn't initialize Listener" << std::endl;
        return;
    }
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(0);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockFD, (struct sockaddr *)&saddr, sizeof(saddr)) == -1) {
        std::cerr << "Couldn't bind Listener" << std::endl;
        close(sockFD);
        return;
    }
    saddr.sin_port = htons(4221);
    saddr.sin_addr.s_addr = inet_addr("234.42.42.42");
    sendto(sockFD, _address.c_str(), _address.size(), 0,
           (struct sockaddr *)&saddr, sizeof(saddr));
    close(sockFD);
}

std::string WarpServer::receive()
{
    char buff[65507];
    int size = sizeof(struct sockaddr_in);

    memset(buff, 0, 65507);
    recvfrom(_sockFD, buff, 65506, 0,
             (struct sockaddr *)&_saddress, (socklen_t *)&size);
    std::string ret(buff);
    return (ret);
}

