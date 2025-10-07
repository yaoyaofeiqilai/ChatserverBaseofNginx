#include "client.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cerr << "command invalid! example: ./ChatClient 127.0.0.1 8000" << endl;
        exit(-1);
    }

    // 解析主函数传入参数信息
    char *ip = argv[1];
    uint16_t port = atoi(argv[2]);

    // 创建客户端网络嵌套字scoket
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd == -1)
    {
        cerr << "create scoket failed!";
        exit(-1);
    }

    // 填写客户端连接的服务器信息
    sockaddr_in server;
    memset(&server, 0, sizeof(sockaddr_in));

    server.sin_family = AF_INET; // 协议ipv4
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    // 尝试连接服务器
    if (connect(clientfd, (sockaddr *)&server, sizeof(sockaddr_in)) == -1)
    {
        cerr << "connect server failed!" << endl;
        close(clientfd);
        exit(-1);
    }

    for (;;)
    {
        // 显示首页面菜单 登录、注册、退出
        cout << "========================" << endl;
        cout << "1. login" << endl;
        cout << "2. register" << endl;
        cout << "3. quit" << endl;
        cout << "========================" << endl;
        cout << "choice:";
        int choice = 0;
        cin >> choice;
        cin.get(); // 读掉缓冲区残留的回车

        switch (choice)
        {
        case 1: // login业务
        {
            login(clientfd);
        }
        break;
        case 2: // register业务
        {
            reg(clientfd);
        }
        break;
        case 3: // quit业务
            close(clientfd);
            exit(0);
        default:
            cerr << "invalid input!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    return 0;
}