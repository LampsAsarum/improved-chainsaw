#include "View.h"

void LoginView::process(int fd,Json::Value &val)
{   cout << "this->LoginView::process()" << endl;
    string cmd = "select password from teacher where id="+val["id"].asString() + ";";
    DataBase::getDB()->Query(cmd.c_str());
    DataBase::getDB()->Result();
    if(val["pw"] == DataBase::getDB()->Row()[0])
    {
        //判断完相等就应该返回ok了
	    //Json::Value root;
        //root["reason"] = "ok";
        SerBridge::getBridge()->send(fd,"ok");
        //sere.sendClient(fd,root.toStyledString().c_str());
    }
    else
    {
        //返回no
	    //Json::Value root;
        //root["reason"] = "no";
        //sere.sendClient(fd,root.toStyledString().c_str());
        SerBridge::getBridge()->send(fd,"no");
    }
}

void RegisterView::process(int fd,Json::Value &val)
{   cout << "this->RegisterView::process()" << endl;/*
    Json::Value val;
    Json::Reader read;
    if(-1 == read.parse(str,val))
    {
        cerr << "read fail errno:" << errno << endl;
        return;
    }*/
    //val["id"]
    //val["pw"]
    string cmd = "insert into teacher values('"+val["id"].asString()+"','"+val["pw"].asString()+"');";
    DataBase::getDB()->Query(cmd.c_str());
    //返回ok
    //Json::Value root;
    //root["reason"] = "ok";
    //sere.sendClient(fd,root.toStyledString().c_str());
    SerBridge::getBridge()->send(fd,"ok");
}

void InsertView::process(int fd,Json::Value &val)
{   cout << "this->InsertView::process()" << endl;/*
    Json::Value val;
    Json::Reader read;
    if(-1 == read.parse(str,val))
    {
        cerr << "read fail errno:" << errno << endl;
        return;
    }*/
    //val["id"];
    //val["name"];
    //val["sex"];
    string cmd = "insert into student values('" + val["id"].asString() + "','" + val["name"].asString() + "','" + val["sex"].asString() + "');";
    DataBase::getDB()->Query(cmd.c_str());
    //返回ok
    //Json::Value root;
    //root["reason"] = "ok";
    //sere.sendClient(fd,root.toStyledString().c_str());
    SerBridge::getBridge()->send(fd,"ok");
}

void DeleteView::process(int fd,Json::Value &val)
{   cout << "this->DeleteView::process()" << endl;/*
    Json::Value val;
    Json::Reader read;
    if(-1 == read.parse(str,val))
    {
        cerr << "read fail errno:" << errno << endl;
        return;
    }*/
    //val["id"];
    string cmd = "delete from student where id=" + val["id"].asString() + ";";
    DataBase::getDB()->Query(cmd.c_str());
    //返回ok
    //Json::Value root;
    //root["reason"] = "ok";
    //sere.sendClient(fd,root.toStyledString().c_str());
    SerBridge::getBridge()->send(fd,"ok");
}

void SelectView::process(int fd,Json::Value &val)
{   cout << "this->SelectView::process()" << endl;/*
    Json::Value val;
    Json::Reader read;
    if(-1 == read.parse(str,val))
    {
        cerr << "read fail errno:" << errno << endl;
        return;
    }*/
    //val["id"];
    string cmd = "select * from student where id=" + val["id"].asString() + ";";
    DataBase::getDB()->Query(cmd.c_str());
    DataBase::getDB()->Result();
    //应该是返回这个DataBase::getDB()->Row()[0];
    cout << "id: " << DataBase::getDB()->Row()[0] << " " << "name: " << DataBase::getDB()->Row()[1] << "sex: " << DataBase::getDB()->Row()[2] << endl;
    //Json::Value root;
    //root["id"] = DataBase::getDB()->Row()[0];
    //root["name"] = DataBase::getDB()->Row()[1];
    //root["sex"] = DataBase::getDB()->Row()[2];
    //string str = 
    //sere.sendClient(fd,root.toStyledString().c_str());
    SerBridge::getBridge()->send(fd,"ok");
}

void UpdateView::process(int fd,Json::Value &val)
{   cout << "this->UpdateView::process()" << endl;/*
    Json::Value val;
    Json::Reader read;
    if(-1 == read.parse(str,val))
    {
        cerr << "read fail errno:" << errno << endl;
        return;
    }*/
    //val["id"];
    //val["name"];
    //val["sex"];
    string cmd = "update student set name=" + val["name"].asString() + ",sex=" + val["sex"].asString() + "where id=" + val["id"].asString() + ";";
    DataBase::getDB()->Query(cmd.c_str());
    //返回ok
    //Json::Value root;
    //root["reason"] = "ok";
    //sere.sendClient(fd,root.toStyledString().c_str());
    SerBridge::getBridge()->send(fd,"ok");
}
