#include "Bridge.h"

Bridge *Bridge::_bridge = NULL;

pthread_mutex_t Bridge::mtx = PTHREAD_MUTEX_INITIALIZER;

int Bridge::send(const string &str)
{
    return cli->sendServer(str);
}

int Bridge::recv(string &str)
{
    return cli->recvServer(str);
}

int Bridge::getFd()
{
    return cli->getFd();
}
