#include "net.h"
#include <syslog.h>
#include <errno.h>

net::net()
{
    syslog(LOG_INFO, "[%s]new net with no init args",MODULE_NAME);
}

void net::init()
{
    int handler = socket(domain, type, protocol);
    if(0 > shdler)
    {
        syslog(LOG_ERR,"[%s]net socket init failed, error(%d)",
                        MODULE_NAME, errno);
    }
    this -> shdler = handler;
    syslog(LOG_INFO, "[%s]new net with domain = %d, type = %d, protocol = %d, ret_handler = %d",
                MODULE_NAME, domain, type, protocol, handler);
}

net::net(int domain, int type, int protocol)
{
    this -> domain = domain;
    this -> type = type;
    this -> protocol = protocol;    
    this -> init();
}
int net::get_shdler()
{
    return shdler;
}