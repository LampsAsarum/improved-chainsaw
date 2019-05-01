#include "SerSystem.h"

void SerSystem::Run()
{
    cout << "this->SerSystem::Run()" << endl;
    //启动工作线程
    WorkPthread WP1;

    lib_base = event_base_new();
    int fd = SerBridge::getBridge()->getFd();
    struct event *listen_event = event_new(lib_base,fd,EV_READ|EV_PERSIST,Listen_cb,lib_base);
    if(NULL == listen_event)
    {
        cerr << "event new fail;errno:" << errno << endl;
        return;
    }
    event_add(listen_event,NULL);
    event_base_dispatch(lib_base);
}

void SerSystem::Listen_cb(int fd,short event,void *arg)
{
    cout << "this->SerSystem::Listen_cb()" << endl;
    struct event_base *lib_base = (struct event_base *)arg;
    int cli = SerBridge::getBridge()->accept();
    struct event *cli_event = event_new(lib_base,cli,EV_READ|EV_PERSIST,Cli_cb,lib_base);
    if(NULL == cli_event)
    {
        cerr << "accept fail;errno:" << errno << endl;
        return ;
    }
    event_add(cli_event,NULL);
}

void SerSystem::Cli_cb(int fd,short event,void *arg)
{
    cout << "this->SerSystem::Cli_cb()" << endl;
    struct event_base *lib_base = (struct event_base *)arg;
    string str;
    int len = SerBridge::getBridge()->recv(fd,str);
    if(len > 0)
    {
        Mqueue::getQue()->push(make_pair(fd,str));
    }
}

