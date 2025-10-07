//数据模块的代码
# ifndef _DB_HPP
#define _DB_HPP

#include <mysql/mysql.h>
#include<string>

using namespace std;
//数据库操作类
class Mysql
{
    public:
    Mysql();

    ~Mysql();

    bool connect();

    bool update(std::string);   //数据库的增删改

    MYSQL_RES* query(std::string);  //数据库的查询

    MYSQL* get_connect();   //获取数据库的连接

    private:
    MYSQL* conn_;
};
#endif