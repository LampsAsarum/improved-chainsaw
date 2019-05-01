#include "TcpServer.h"

TcpServer::TcpServer(const string &ip,const unsigned short port)
{
    createServer(ip,port);
}

void TcpServer::createServer(const string &ip,const unsigned short port)
{
    _ListenFd = socket(AF_INET,SOCK_STREAM,0);
    if(_ListenFd == -1)
    {
        cerr << "socket error" << errno << endl;
        exit(-1);
    }
    
    struct sockaddr_in saddr;
    memset(&saddr,0,sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = inet_addr(ip.c_str());

    int res = bind(_ListenFd,(struct sockaddr *)&saddr,sizeof(saddr));
    if(res == -1)
    {
        cerr << "bind error" << errno << endl;
        exit(-1);
    }
    
    int lis = listen(_ListenFd,20);
    if(lis == -1)
    {
        cerr << "listen error" << errno << endl;
        exit(-1);
    }
}

int TcpServer::acceptClient()
{
    struct sockaddr_in caddr;
    socklen_t len = sizeof(caddr);
    int cli_fd = accept(_ListenFd,(struct sockaddr *)&caddr,&len);
    if(-1 == cli_fd)
    {
        cerr << "accept error" <<errno << endl;
    }
    return cli_fd;//服务器用这个来进行数据的交互
}

int TcpServer::recvClient(int cliFd,string &str)
{
    char buff[128] = {0};
    int len = recv(cliFd,buff,127,0);
    str = buff;
    return len;
}

int TcpServer::sendClient(int cliFd,const string &str)
{
    int flg = send(cliFd,str.c_str(),strlen(str.c_str()),0);
    return flg;
}

int TcpServer::getListenFd()
{
    return _ListenFd;
}
