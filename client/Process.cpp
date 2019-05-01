#include "Process.h"

void Process::Put()
{
    cout << "*******Process******" << endl;
    cout << "********************" << endl;
    cout << "---- 1、insert  ----" << endl;
    cout << "---- 2、select  ----" << endl;
    cout << "---- 3、update  ----" << endl;
    cout << "---- 4、delete  ----" << endl;
    cout << "---- 5、exit    ----" << endl;
    cout << "********************" << endl;
}

void Process::Run()
{
    int n = 0;
    while(1)
    {
        Put();
        cin >> n;
        switch(n)
        {
            case 1:
                Insert();
                break;
            case 2:
                Select();
                break;
            case 3:
                Update();
                break;
            case 4:
                Delete();
                break;
            case 5:
                return ;
            default:
                cout << "input error,again: " << endl;
                continue;
        }
    }
}

void Process::Insert()
{
    string id; cout << "id(int): "; cin >> id;
    string name; cout << "name(str): "; cin >> name;
    string sex; cout << "sex(str): "; cin >> sex;

    Json::Value val;
    val["type"] = "INSERT";
    val["id"] = id;
    val["name"] = name;
    val["sex"] = sex;
    Bridge::getBridge()->send(val.toStyledString().c_str());
    //string str;
    //Bridge::getBridge()->recv(str);
    //cout << str << endl;
}


void Process::Select()
{
    string id; cout << "id(int): "; cin >> id;
    //string name; cout << "name: " << endl; cin >> name;
    //string sex; cout << "sex: " << endl; cin >> sex;

    Json::Value val;
    val["type"] = "SELECT";
    val["id"] = id;
    //val["name"] = name;
    //val["sex"] = sex;
    Bridge::getBridge()->send(val.toStyledString().c_str());
    //string str;
    //Bridge::getBridge()->recv(str);
    //cout << str << endl;
}

void Process::Update()
{
    string id; cout << "update id(int): "; cin >> id;
    string name; cout << "update name(str): "; cin >> name;
    string sex; cout << "update sex(str): "; cin >> sex;

    Json::Value val;
    val["type"] = "UPDATE";
    val["id"] = id;
    val["name"] = name;
    val["sex"] = sex;
    Bridge::getBridge()->send(val.toStyledString().c_str());
    //string str;
    //Bridge::getBridge()->recv(str);
    //cout << str << endl;
}


void Process::Delete()
{
    string id; cout << "id(int): "; cin >> id;
    //string name; cout << "name: " << endl; cin >> name;
    //string sex; cout << "sex: " << endl; cin >> sex;

    Json::Value val;
    val["type"] = "DELETE";
    val["id"] = id;
    //val["name"] = name;
    //val["sex"] = sex;
    Bridge::getBridge()->send(val.toStyledString().c_str());
    //string str;
    //Bridge::getBridge()->recv(str);
    //cout << str << endl;
}
