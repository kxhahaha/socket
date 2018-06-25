#ifndef __server_CPP_H__
#define __server_CPP_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <fstream>

#include "rnt.h"

using namespace std;

#define MODULE_NAME "server"

class server
{
    private:
        int shdler = 0;
        int domain = AF_INET;
        int type = SOCK_STREAM;
        int protocol = 0;
        struct sockaddr_in* addr;
        string finit = ".ini";  //配置文件路径及文件名
        fstream finihlder;

        struct sockaddr_in* getaddr(const string finit);
    public:
        server();
        int get_shdler();  //获得操作句柄
        rnt_e init();  //初始化，返回socket句柄
        void set_fini(string fini);
        fstream& get_finihdler();
        ~server();

};


#endif //__server_CPP_H__