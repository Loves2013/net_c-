/*
 * @Author: abin
 * @Date: 2024-05-31 18:11:08
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-06-02 13:58:12
 * @FilePath: /github/EPollPoller.h
 * @Description: 
 * epoll 的使用
 *  epoll_crerate
 *  epoll_ctl
 *  epoll_wait
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#include "Poller.h"
#include <vector>
#include <sys/epoll.h>
#include <functional>
#include <string>
#include "Timestamp.h"
class Channel;
class EPollPoller : public Poller{
public:
    EPollPoller(EventLoop* loop);
    ~EPollPoller() override;

    Timestamp poll(int timeoutMs,ChannelList *actoveChannelList) override;

    /* 对应的 epoll_ctl*/
    void updateChannel(Channel* channel) override;
    void removeChannel(Channel* channel) override;

private:
    static const int kIntEventListSize = 16;
    /* 填写活跃的channel 连接*/
    void fillActiveChannels(int numEvents,ChannelList* activeChannels) const;
    /* 跟新连接*/
    void update(int operation,Channel* channel);

    typedef std::vector<struct epoll_event> EventList;
    int epollfd_;
    /* 存放发生事件的fd 的数量 */
    EventList events_;
};