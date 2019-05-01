#pragma once
#include <iostream>
#include <queue>
#include <map>
#include <pthread.h>
using namespace std;

class Mqueue
{
    public:
        static Mqueue *getQue();
        pair<int,string> pop();
        void push(pair<int,string> data);
    private:
        queue< pair<int,string> > que;
        Mqueue()
        {
	    cout << "this->Mqueue.cpp::Mqueue()" << endl;
        }
        static Mqueue *_que;
        static pthread_mutex_t qtx;
};
