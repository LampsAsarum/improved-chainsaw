#include "WorkPthread.h"

WorkPthread::WorkPthread()
{
    cout << "this->WorkPthread.cpp::WorkPthread()" << endl;
    pthread_create(&tid,NULL,WorkPthread::Run,NULL);
}

void * WorkPthread::Run(void *)
{
    cout << "this->WorkPthread.cpp::Run(void *)" << endl;
    pthread_detach(pthread_self());
    while(1)
    {
        pair<int,string> data = Mqueue::getQue()->pop();
        Contral::getContral()->Process(data);
    }
}
