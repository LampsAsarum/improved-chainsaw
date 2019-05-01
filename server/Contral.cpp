#include "Contral.h"

Contral *Contral::_con = NULL;

pthread_mutex_t Contral::ctx = PTHREAD_MUTEX_INITIALIZER;

void Contral::Process(pair<int,string> data)
{cout << "this->Contral.cpp::Process()" << endl;
    Json::Value val;
    Json::Reader read;
    if(-1 == read.parse(data.second,val))
    {
        cerr << "read fail;errno:" << errno << endl;
        return ;
    }
    _map[val["type"].asString()]->process(data.first,val);
}
