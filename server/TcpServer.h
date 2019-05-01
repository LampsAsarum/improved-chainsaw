#pragma once
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
using namespace std;

class TcpServer
{
    private:
        int _ListenFd;
    public:
        TcpServer(const string &ip,const unsigned short port);//调用create
        void createServer(const string &ip,const unsigned short port);
        int acceptClient();
        int recvClient(int cliFd,string&);
        int sendClient(int cliFd,const string&);
        int getListenFd();
};
