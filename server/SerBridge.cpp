#include "SerBridge.h"

SerBridge *SerBridge::_serbridge = NULL;

pthread_mutex_t SerBridge::stx = PTHREAD_MUTEX_INITIALIZER;

int SerBridge::send(int cli,const string &str)
{
    cout << "this->SerBridge::send()" << endl;
    return ser->sendClient(cli,str);
}

int SerBridge::recv(int cli,string &str)
{
    cout << "this->SerBridge::recv()" << endl;
    return ser->recvClient(cli,str);
}

int SerBridge::getFd()
{
    cout << "this->SerBridge::getFd()" << endl;
    return ser->getListenFd();
}

int SerBridge::accept()
{
    cout << "this->SerBridge::accept()" << endl;
    return ser->acceptClient();
}
