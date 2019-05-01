#pragma once
#include <iostream>
#include <string>
#include <map>
#include <json/json.h>
#include <errno.h>
#include <pthread.h>
#include "View.h"
using namespace std;

class Contral
{
    private:
        Contral()
        {
  	        cout << "this->Contral.cpp::Contral()" << endl;
            _map.insert(make_pair("LOGIN",new LoginView() ));
            _map.insert(make_pair("REGISTER",new RegisterView() ));
            _map.insert(make_pair("INSERT",new InsertView() ));
            _map.insert(make_pair("DELETE",new DeleteView() ));
            _map.insert(make_pair("SELECT",new SelectView() ));
            _map.insert(make_pair("UPDATE",new UpdateView() ));
        }
	    map<string,View *> _map;
        static Contral *_con;
        static pthread_mutex_t ctx;
    public:
        static Contral *getContral()
        {cout << "this->Contral.cpp::getContral()" << endl;
            if(NULL == _con)
            {
                pthread_mutex_lock(&ctx);
                if(NULL == _con)
                {
                    _con = new Contral();
                }
                pthread_mutex_unlock(&ctx);
            }
            return _con;
        }
        void Process(pair<int,string> data);
};
