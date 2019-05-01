#pragma once
#include <iostream>
#include <pthread.h> 
#include "Mqueue.h"
#include "Contral.h"
using namespace std;

class WorkPthread
{
    public:
        WorkPthread();
        static void *Run(void *);
    private:
        pthread_t tid;
};

