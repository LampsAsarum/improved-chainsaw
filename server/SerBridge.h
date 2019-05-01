#pragma once 
#include <iostream>
#include "TcpServer.h"
#include <pthread.h>
using namespace std;

class SerBridge
{
    private:
        SerBridge(const string &ip,const unsigned port)
        {
	    cout << "this->SerBridge::SerBridge()" << endl;
            ser = new TcpServer(ip,port);
        }
        static SerBridge *_serbridge;
        TcpServer *ser;
    public:
        static SerBridge *getBridge()
        {
	    cout << "this->SerBridge::getBridge()" << endl;
            if(NULL == _serbridge)
            {
                pthread_mutex_lock(&stx);
                if(NULL == _serbridge)
                {
                    _serbridge = new SerBridge("127.0.0.1",6001);
                }
                pthread_mutex_unlock(&stx);
            }
            return _serbridge;
        }
        int send(int cli,const string &str);
        int recv(int cli,string &str);
        int getFd();
        int accept();
        static pthread_mutex_t stx;
};
