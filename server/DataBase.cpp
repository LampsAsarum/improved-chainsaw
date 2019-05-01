#include "DataBase.h"

DataBase *DataBase::_DB = NULL;

pthread_mutex_t DataBase::dtx = PTHREAD_MUTEX_INITIALIZER;

void DataBase::Query(const char *cmd)
{
    cout << "this->DataBase::Query()" << endl;
    if(mysql_real_query(mpcon,cmd,strlen(cmd)))
    {
        cerr << "query fail;errno:" << errno << endl;
        return ;
    }
}

MYSQL_RES* DataBase::Result()
{
    cout << "this->DataBase::Result()" << endl;
    mp_res = mysql_store_result(mpcon);
    return mp_res;
}

MYSQL_ROW DataBase::Row()
{
    cout << "this->DataBase::Row()" << endl;
    mp_row = mysql_fetch_row(mp_res);
    return mp_row;
}

void DataBase::FreeResult()
{
    cout << "this->DataBase::FreeResult()" << endl;
    mysql_free_result(mp_res);
}

void DataBase::Close()
{
     cout << "this->DB::close()" << endl;
    mysql_close(mpcon);
}
