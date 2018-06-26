#include "server.h"
#include <syslog.h>
#include <errno.h>
#include <string>
#include <iostream>
#include <fstream>

#include "rnt.h"
#include "json.h"

using namespace std;
using namespace Json;

struct sockaddr_in* server::getaddr(const string finit)
{

}

server::server()
{
    syslog(LOG_INFO, "[%s]new server with no init args",MODULE_NAME);
}

rnt_e server::init()
{
    //打开配置文件
    finihlder.open(finit, ios::out | ios::in);
    
    if(errno != 0)
    {
        syslog(LOG_ERR,"open file(%s) failed,err(%d)",finit,errno);
        return rnt_fopen_e;
    }

    syslog(LOG_INFO, "server open init file.");

    //读取配置文件
    if(finit.empty())
    {
        syslog(LOG_ERR, "init file is NOT EXIST");
    }

    finihlder.open(finit);
   

    //配置文件转换为Json




    int shdler = socket(domain, type, protocol);
    if(0 > shdler)
    {
        syslog(LOG_ERR,"[%s]server socket init failed, error(%d)",
                        MODULE_NAME, errno);
    }
    syslog(LOG_INFO, "[%s]new server with domain = %d, type = %d, protocol = %d, ret_handler = %d",
                    MODULE_NAME, domain, type, protocol, shdler);

    
}

Json::Value server::getJson()
{
    Json::Value jsonRoot;  //定义根节点
    Json::Value jsonItem; //定义子对象

    jsonRoot.clear();
    jsonItem.clear();

    Json::CharReaderBuilder jbuilder;
    jbuilder["collectComments"] = false;
    JSONCPP_STRING err;

    if(!parseFromStream(jbuilder, finihlder, &jsonRoot, &err));
    
}

int server::get_shdler()
{
    return shdler;
}