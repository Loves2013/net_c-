/*
 * @Author: abin
 * @Date: 2024-05-28 16:22:35
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-28 16:30:48
 * @FilePath: /github/DefaultPoller.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#include "Poller.h"
#include <stdlib.h>

Poller* Poller::newDefaultPoller(EventLoop* loop) {
    /* 环境变量是否在*/
    if(::getenv("MUDUO_USE_POLL")) {
        return nullptr;
    }
    else {
        return nullptr;
    }
}