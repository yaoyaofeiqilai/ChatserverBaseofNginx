//ChatServer类的定义
#include "chatserver.hpp"
#include <functional>
#include <iostream>
#include <string>
#include "json.hpp"
#include <string>
#include "chatservice.hpp"

using json =nlohmann::json;
using namespace std::placeholders;
//初始化构造函数，同时设置事件的回调函数
ChatServer::ChatServer(EventLoop* loop,const InetAddress& listenAddr,const string& nameArg)
:server_(loop,listenAddr,nameArg)
,loop_(loop)
{
    //连接断开事件的回调函数
    server_.setConnectionCallback(std::bind(&ChatServer::ServerConnFunc,this,_1));
    //读写事件对调函数
    server_.setMessageCallback(std::bind(&ChatServer::ServerMessFunc,this,_1,_2,_3));
    //设置服务器线程
    server_.setThreadNum(4);
}

void ChatServer::start()
{
    server_.start();
}

//处理连接事件的函数定义
void ChatServer::ServerConnFunc(const TcpConnectionPtr&conn)
{
   if(!conn->connected())  //关闭连接的代码
   {
      ChatService::instance()->closeException(conn);  //设置用户状态函数
      conn->shutdown();
   }

}

//处理信息读写事件的函数定义
void ChatServer::ServerMessFunc(const TcpConnectionPtr&conn,Buffer*buffer,Timestamp time)
{
  //将缓冲区的信息转为字符串
   string str=buffer->retrieveAllAsString();
   //将字符串内容反序列化为json
   json js=json::parse(str);
   //目的：将业务模块代码与网络模块的代码解耦
   //放回信息类型的处理函数
   MsgHandler msghandler=ChatService::instance()->getHandler(js["msgid"].get<int>());
   //调用消息处理函数，进行业务处理
   msghandler(conn,js,time);
}
