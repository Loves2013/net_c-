/*
 * @Author: abin
 * @Date: 2024-05-27 19:53:46
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-27 20:22:29
 * @FilePath: /github/InetAddress.h
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#ifndef MUDUO_INTADDRESS_H
#define MUDUO_INTADDRESS_H
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

namespace muduo {
class InetAddress {
public:
    explicit InetAddress(uint16_t port,std::string ip = "127.0.0.1");
    explicit InetAddress(const sockaddr_in &addr) :addr_(addr) {}
    ~InetAddress();
    uint16_t toPort() const ;

    std::string toIp() const;
    std::string toIpPort() const;
    const sockaddr_in* getSockAddr() const  { return &addr_;}
private:
    sockaddr_in addr_;

};
}

#endif // !MUDUO_INTADDRESS_H
