#pragma once
#include <iostream>
#include <string.h>
#include <errno.h> 
#include <json/json.h>
#include "DataBase.h"
#include "TcpServer.h"
#include "SerBridge.h"
using namespace std;
class View
{
    public:
        virtual void process(int fd,Json::Value &val) = 0;
};

class LoginView:public View
{
    public:
        void process(int fd,Json::Value &val);
};

class RegisterView:public View
{
    public:
        void process(int fd,Json::Value &val);
};

class InsertView:public View
{
    public:
        void process(int fd,Json::Value &val);
};

class DeleteView:public View
{
    public:
        void process(int fd,Json::Value &val);
};

class SelectView:public View
{
    public:
        void process(int fd,Json::Value &val);
};

class UpdateView:public View
{
    public:
        void process(int fa,Json::Value &val);
};


