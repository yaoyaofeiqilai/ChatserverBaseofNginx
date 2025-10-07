#ifndef OFFLINEMSGOPERATE_HPP
#define OFFLINEMSGOPERATE_HPP
#include <vector>
#include <string>
using namespace std;
class OfflineMsgOperate
{
    public:
    //添加离线消息
    void insertOfflineMsg(int id,string msg);

    //移除离线消息
    void removeOfflineMsg(int id);

    //查询离线消息
    vector<string> queryOfflineMsg(int id);
    
};
#endif