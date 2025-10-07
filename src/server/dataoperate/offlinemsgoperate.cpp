#include "offlinemsgoperate.hpp"
#include "db.hpp"
// 添加离线消息
void OfflineMsgOperate::insertOfflineMsg(int id, string msg)
{
    // 组装sql语句
    char sql[1024];
    sprintf(sql, "insert into OfflineMessage values(%d,'%s')", id, msg.c_str());

    Mysql mysql;
    if (mysql.connect())
    {
        // 插入消息
        mysql.update(sql);
    }
}

// 移除离线消息
void OfflineMsgOperate::removeOfflineMsg(int id)
{
    char sql[1024];
    sprintf(sql, "delete from OfflineMessage where userid=%d", id);

    Mysql mysql;
    if (mysql.connect())
    {
        // 删除所有的离线消息
        mysql.update(sql);
    }
}

// 查询离线消息
vector<string> OfflineMsgOperate::queryOfflineMsg(int id)
{
    // 组装sql语句
    char sql[1024];
    vector<string> msglist;
    sprintf(sql, "select message from OfflineMessage where userid=%d", id);

    Mysql mysql;
    if (mysql.connect()) // 连接数据库
    {
        MYSQL_RES *res = mysql.query(sql); // 返回查询结果
        if (res != nullptr)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                msglist.push_back(row[0]);
            }
            mysql_free_result(res); // 释放资源
        }
    }
    return msglist;
}