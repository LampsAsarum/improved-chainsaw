#include "Mqueue.h"

Mqueue *Mqueue::_que = NULL;

pthread_mutex_t Mqueue::qtx = PTHREAD_MUTEX_INITIALIZER;

Mqueue * Mqueue::getQue()
{
    cout << "this->Mqueue.cpp::getQue()" << endl;
    if(NULL == _que)
    {
        pthread_mutex_lock(&qtx);
        if(NULL == _que)
        {
            _que = new Mqueue();
        }
        pthread_mutex_unlock(&qtx);
    }
    return _que;
}

pair<int,string> Mqueue::pop()
{
    cout << "this->Mqueue.cpp::pop()" << endl;
    while(1)
    {
        if(!que.empty())
        {
	        pthread_mutex_lock(&qtx);
	        pair<int,string> pai = que.front();
	        que.pop();
	        pthread_mutex_unlock(&qtx);
	        return pai;
        }
        else
        {
	        cout << "this->Mqueue.cpp::pop(),sleep(1)" << endl;
	        sleep(1);
        }
    }
}

void Mqueue::push(pair<int,string> data)
{
    cout << "this->Mqueue.cpp::push()" << endl;
    que.push(data);
}
