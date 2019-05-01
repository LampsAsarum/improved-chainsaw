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

class TcpClient
{
    private:
        int _fd;//这个就是用来与服务器交互的文件描述符
    public:
        TcpClient(const string &ip,const unsigned short port);
        void connectServer(const string &ip,const unsigned short port);
        int recvServer(string &str);
        int sendServer(const string &str);
        int getFd();
};
