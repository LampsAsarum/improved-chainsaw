#include "TcpClient.h"

TcpClient::TcpClient(const string &ip,const unsigned short port)
{
    connectServer(ip,port);
}

void TcpClient::connectServer(const string &ip,const unsigned short port)
{
    _fd = socket(AF_INET,SOCK_STREAM,0);
    if(_fd == -1)
    {
        cerr << "socket error" << errno << endl;;
        return;
    }

    struct sockaddr_in saddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = inet_addr(ip.c_str());

    int flg = connect(_fd,(struct sockaddr *)&saddr,sizeof(saddr));
    if(flg == -1)
    {
        cerr << "sonnect error" << errno << endl;
        return;
    }
}

int TcpClient::recvServer(string &str)
{
    char buff[128] = {0};
    int flg = recv(_fd,buff,127,0);
    str = buff;
    if(flg == -1)
    {
        cerr << "recv error" << errno << endl;
    }
    return flg;
}

int TcpClient::sendServer(const string &str)
{
    int flg = send(_fd,str.c_str(),strlen(str.c_str()),0);
    if(flg == -1)
    {
        cerr << "send error" << errno << endl;
    }
    return flg;
}

int TcpClient::getFd()
{
    return _fd;
}
