#include "server.h"
#include <syslog.h>
#include <errno.h>
#include <string>
#include "cJSON.h"

using namespace std;

struct sockaddr_in* server::getaddr(const string finit)
{
    
}


server::server()
{
    syslog(LOG_INFO, "[%s]new server with no init args",MODULE_NAME);
}

void server::init()
{
    int shdler = socket(domain, type, protocol);
    if(0 > shdler)
    {
        syslog(LOG_ERR,"[%s]server socket init failed, error(%d)",
                        MODULE_NAME, errno);
    }
    syslog(LOG_INFO, "[%s]new server with domain = %d, type = %d, protocol = %d, ret_handler = %d",
                    MODULE_NAME, domain, type, protocol, shdler);
}

int server::get_shdler()
{
    return shdler;
}