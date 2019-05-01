#include "System.h"

void System::Put()
{
    cout << "********System*******" << endl;
    cout << "*********************" << endl;
    cout << "---- 1、login    ----" << endl;
    cout << "---- 2、register ----" << endl;
    cout << "---- 3、exit     ----" << endl;
    cout << "*********************" << endl;
}

void System::Run()
{
    int n = 0;

    while(1)
    {
        Put();
        cin >> n;
        switch(n)
        {
            case 1:
                Login();
                break;
            case 2:
                Register();
                break;
            case 3:
                return;
            default:
                cout << "input error,again: " << endl;
        }
    }
}

void System::Login()
{
    string id;
    cout << "id: ";
    cin >> id;

    string pw;
    cout << "password: ";
    cin >> pw;

    //创建json包
    Json::Value val;
    val["type"] = "LOGIN";
    val["id"] = id;
    val["pw"] = pw;
    Bridge::getBridge()->send(val.toStyledString().c_str());
    
    //这里将数据发送之后，如果根数据库的内容匹配上，就说明登录成功，成功之后，进入下一个页面
    string str;
    Bridge::getBridge()->recv(str);
    /*
    Json::Value reason;
    Json::Reader read;
    if(-1 == read.parse(str,reason))
    {
        cerr << "read fail errno:" << errno << endl;
        return ;
    }
    cout << "reason:" << reason["reason"].asString() << endl;*/
    //if(strcmp(reason["reason"].asString().c_str(),"ok") == 0)
    if(strcmp(str.c_str(),"ok") == 0)
    {
        //pthread_t tid;
        //pthread_create(&tid,NULL,Recv,(void*)Bridge::getBridge()->getFd());
        cout << "ok" << endl;
        pro.Run();
    }
    else
    {
        cout << "you need register." << endl;
        Run();
    }
}

void System::Register()
{
    string id;
    cout << "please cin register id: ";
    cin >> id;

    string pw;
    cout << "please cin register password: ";
    cin >> pw;
    
    Json::Value val;
    val["type"] = "REGISTER";
    val["id"] = id;
    val["pw"] = pw;
    Bridge::getBridge()->send(val.toStyledString().c_str());
    
    string str;
    Bridge::getBridge()->recv(str);
    /*
    Json::Value reason;
    Json::Reader read;
    if(-1 == read.parse(str,reason))
    {
        cerr << "read fail errno:" << errno << endl;
        return ;
    }*/

    if(strcmp(str.c_str(),"ok") == 0)
    {
        cout << "ok" << endl;
        Login();
    }
}

void *Recv(void *fd)
{
    pthread_detach(pthread_self());
    int cli = (int)fd;
    string str;
    char buff[128] = {0};
    while(1)
    {
        Bridge::getBridge()->recv(str);
        //cli.recvServer(str);
        //if( recv(cli,buff,127,0) <= 0)
        //{
        //    break;
        //}
        //str = buff;
        /*
        Json::Value reason;
        Json::Reader read;
        if(-1 == read.parse(str,reason))
        {
            cerr << "read fail errno:" << errno << endl;
            return NULL;
        }
        cout << "reason:" << reason["reason"].asString() << endl;*/
        if(!str.empty())
        {
            cout << "reason: "  << str << endl;
        }
    }
    cout << "once over " << endl;
    close(cli);
}
