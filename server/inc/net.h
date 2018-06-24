#ifndef __NET_CPP_H__
#define __NET_CPP_H__

#include <sys/types.h>
#include <sys/socket.h>

#define MODULE_NAME "socket_c"

class net
{
    private:
        int shdler = 0;
        int domain = 0;
        int type = 0;
        int protocol = 0;
    public:
        net();
        net(int domain, int type, int protocol); //初始化为0,0,0
        int get_shdler();  //获得操作句柄
        void init();  //初始化，返回socket句柄
        ~net();

};


#endif //__NET_CPP_H__