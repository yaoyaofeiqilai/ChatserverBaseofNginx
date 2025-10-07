#ifndef GROUPOPERATE_HPP
#define GROUPOPERATE_HPP
#include "group.hpp"
class GroupOperata
{
    public:
    //创建组
    bool createGroup(Group& group);

    //加入组
    bool addGroup(int userid,int groupid,string role);

    //查询组成员
    vector<int> queryNumber(int groupid,int);

    //查询用户加入的组信息
    vector<Group> queryGroup(int userid);
};
#endif