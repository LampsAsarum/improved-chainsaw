#pragma once
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "TcpClient.h"
using namespace std;

class Bridge
{
    private:
        Bridge(const string &ip,const unsigned short port)
        {
            cli = new TcpClient(ip,port);
        }
        static Bridge * _bridge;
        TcpClient *cli;
    public:
        static Bridge *getBridge()
	    {
	        if(NULL == _bridge)
	        {
		        pthread_mutex_lock(&mtx);
		        if(NULL == _bridge)
		        {
		            /*cout << "请输入ip与port：" << endl;
		            string ip;
		            unsigned short port;
		            cin >> ip;
		            cin >> port;*/
		            _bridge = new Bridge("127.0.0.1",6001);
		        }
		        pthread_mutex_unlock(&mtx);
	        }
	        return _bridge;
	    }
        int send(const string &str);
        int recv(string &str);
        int getFd();
        static pthread_mutex_t mtx;
};
