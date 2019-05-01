#pragma once
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <json/json.h>
#include <pthread.h>
#include "Process.h"
#include "Bridge.h"
using namespace std;

class System
{
    public:
        System()//:pro("127.0.0.1",6001)
        {}
        void Put();
        void Run();
        void Login();
        void Register();
    private:
        Process pro;
};

void *Recv(void *fd);
