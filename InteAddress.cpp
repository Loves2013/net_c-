/*
 * @Author: abin
 * @Date: 2024-05-27 19:51:28
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-28 00:49:32
 * @FilePath: /github/InteAddress.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#include <unistd.h>
#include "InetAddress.h"
namespace muduo 
{
InetAddress::InetAddress(uint16_t port,std::string ip) {
    memset(&addr_,0,sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
}

std::string InetAddress::toIp() const {
    char buf[64] = {0};
    ::inet_ntop(AF_INET,&addr_.sin_addr,buf,sizeof(buf));
    return buf;
}

uint16_t InetAddress::toPort() const {
    return ntohs(addr_.sin_port);
}

std::string InetAddress::toIpPort() const {
    char buf[64] = {0};
    ::inet_ntop(AF_INET,&addr_.sin_addr,buf,sizeof(buf));
    uint16_t port = ntohs(addr_.sin_port);
    size_t end = strlen(buf);
    sprintf(buf+end,":%u",port);
    return buf;
}

}
