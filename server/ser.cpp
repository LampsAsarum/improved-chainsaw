#include <iostream>
#include "WorkPthread.h"
#include "SerSystem.h"
using namespace std;

//服务器端使用libevent监听事件
int main()
{
    cout << "this->ser.cpp::main()" << endl;
    SerSystem SerS;
    SerS.Run();
    
    //WorkPthread WP1;//服务器端打开三个线程
    //WorkPthread WP2;
    //WorkPthread WP3;

    return 0;
}
