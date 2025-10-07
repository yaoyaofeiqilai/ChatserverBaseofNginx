#ifndef USER_HPP
#define USER_HPP
//这是对数据库中关于user表的映射
//这样就可以通过对象来更新数据，避免了频繁访问数据库
#include <string>
using namespace std;
class User
{
    public:

    //构造函数
    User(int id,string name,string passworld,string state="offline")
    :id_(id)
    ,name_(name)
    ,password_(passworld)
    ,state_(state)
    {}

    User()
    :id_(-1)
    ,state_("offline")
    {}
    
    ~User()=default;


    void set_id(int id)
    {
        id_=id;
    }
    //更改姓名
    void set_name(string name)
    {
        name_=name;
    }

    //更改密码
    void set_password(string pwd)
    {
        password_=pwd;
    }

    //更改状态
    void set_state(string state)
    {
        state_=state;
    }
    //获取id
    int get_id()
    {
        return id_;
    }

    string get_name()
    {
        return name_;
    }

    string get_password()
    {
        return password_;
    }
    string get_state()
    {
        return state_;
    }
    private:
    int id_;
    string name_;
    string password_;
    string state_;

};
#endif