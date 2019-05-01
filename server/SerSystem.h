#include <iostream>
#include <event.h>
#include <json/json.h>
#include "SerBridge.h"
#include "Mqueue.h"
#include "WorkPthread.h"
using namespace std;

class SerSystem
{
    public:
        void Run();
        static void Listen_cb(int fd,short event,void *arg);
        static void Cli_cb(int fd,short event,void *arg);
    private:
        struct event_base *lib_base;
};
