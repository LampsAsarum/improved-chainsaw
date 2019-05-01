#pragma once
#include <iostream>
#include <mysql/mysql.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
using namespace std;

class DataBase
{
    private:
        DataBase()
        {
            cout << "this->DataBase.cpp::DataBase()" << endl;
            mpcon = mysql_init((MYSQL *)0);//初始化mysql，创建一个数据库对应指针

            //链接mysql 参数：数据库指针，ip，数据库名，密码，端口号
            if(!mysql_real_connect(mpcon,"127.0.0.1","root","111111",NULL,3306,NULL,0))
            {
                cerr << "sql connect fail;errno: " << errno <<endl;
                return ;
            }
            //选择数据库     数据库指针，库名
            if(mysql_select_db(mpcon,"message"))
            {
                cerr << "select fail;errno:" << errno << endl;
                return;
            }
        }
        static DataBase * _DB;
        MYSQL *mpcon;
        MYSQL_RES *mp_res;//接收指令的返回值
        MYSQL_ROW mp_row;//获取返回值的一行
    public:
        static DataBase *getDB()
        {cout << "DataBase->getDB()" <<endl;
            if(NULL == _DB)
            {
                pthread_mutex_lock(&dtx);
                if(NULL == _DB)
                {
                    _DB = new DataBase();
                }
                pthread_mutex_unlock(&dtx);
            }
            return _DB;
        }
        void Query(const char *cmd);
        MYSQL_RES* Result();
        MYSQL_ROW Row();
        void FreeResult();
        void Close();
        static pthread_mutex_t dtx;
};
