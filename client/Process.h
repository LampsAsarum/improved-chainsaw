#pragma once
#include <iostream>
#include <json/json.h>
#include "TcpClient.h"
#include "Bridge.h"
using namespace std;

class Process
{
    public:
        //Process(const string &ip,const unsigned short port):cli(ip,port)
        //{}
	Process()
	{}
        void Put();
        void Run();
        void Insert();
        void Delete();
        void Select();
        void Update();
    private:
        //TcpClient cli;
};
