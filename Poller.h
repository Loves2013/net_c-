/*
 * @Author: abin
 * @Date: 2024-05-28 15:45:30
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-28 16:09:16
 * @FilePath: /github/Poller.h
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#pragma once

#include <vector>
#include <unordered_map>
#include "Timestamp.h"
/* muduo 库中多路事件分发器的核心IO 复用模式 */

class Channel;
class EventLoop;
class Poller {
public:
    typedef std::vector<Channel*> ChannelList;

    Poller(EventLoop* loop);
    virtual ~Poller();
    /* 给所有IO复用保留统一的接口 */
    virtual timespec poll(int timeoutMs,ChannelList* activeChannels) = 0;
    virtual void updateChannel(Channel* channel) = 0;
    virtual void removeChannel(Channel* channel) = 0;
    /* 判断参数channel 是否在当前poller当中*/
    bool hasChannel(Channel* channel) const; 
    /* EventLoop 可以通过该接口获取默认IO复用的具体实现 */
    static Poller* newDefaultPoller(EventLoop* loop);
protected:
    /* map的key: sockfd value： sockfd 所属的channel通道的类型 */
    typedef std::unordered_map<int,Channel*> ChannelMap;
    ChannelMap channels_;
private:
    EventLoop* ownerLoop_;

};