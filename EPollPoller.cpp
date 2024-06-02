/*
 * @Author: abin
 * @Date: 2024-06-02 11:16:40
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-06-02 16:49:33
 * @FilePath: /github/EPollPoller.cpp
 * @Description: 
 *  创建了epoll_create 创建了ep_fd;
 *  创建了epoll_events_
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#include "EPollPoller.h"
#include <stdio.h>
#include "Channel.h"
class Channel Channel;
const int kNew = -1;
const int kAdded = 1;
const int kDeleted = 2;

EPollPoller::EPollPoller(EventLoop* loop)
    : Poller(loop)
    , epollfd_(::epoll_create1(EPOLL_CLOEXEC))
    , events_(kIntEventListSize)
{
     if(epollfd_ < 0) {
        printf("epollfd failed\n");
     }   
}
EPollPoller::~EPollPoller() {
    ::close(epollfd_);
}
/*
    epoll_wait()  = 0,超时 < 0 发生错误, >0  
*/
Timesstamp EpollPoller::poll(int timeoutMs,ChannelList* activeChannels)  
{   /* 解应用 */
    int numEvent = ::epoll_wait(epllfd_,&*events_.begin(),static_cast<int>(events_.size()),timeoutMs);
    int saveErrno = errno;
    /* 有事件 */
    if(numEvents > 0) {
        fillActiveChannels(numEvents,activeChannels);
        if(numEvents == events_.size()) {
            events_.resize(events_.size()* 2);
        }
    
    }
    else if(numEvents == 0) {
        printf("timeout \n");
    }else {
        if(saveErrno != EINTR) {
            errno = saveErrno; 
        }
    }
    return now();
}
/* channel update remove->EventLoop updateChannel removeChannel ==> Pooller*/
void EpollPoller::updateChannel(Channel* channel) {

    const int index = channel->index();
    if(index == kNew || index == kDeleted) {
        int fd = channel->fd();
        if(index == kNew) {
            channels_[fd] = channel;
        }else {
            printf("index 问题\n");
        }
        channel->set_index(kAdded);
        update(EPOLL_CTL_ADD,channel);
    } else { /* channel 已经在poller 上注册过了 */
        int fd = channel->fd();
        (void) fd;
        if(channel->isNoneEvent) {
            update(EPOLL_CTL_DEL,channel);
            channel->set_index(kDeleted);
        }
        else {
            update(EPOLL_CTL_MOD,channel);
        }
    }
}

void EpollerPoller::removeChannel(Channel* channel) {
    int fd = channel->fd();
    int index = channel->index();
    size_t n = channels_erase(fd);
    if(index == kAdded) {
        update(EPOLL_CTL_DEL,channel);
    }
    channel->set_index(kNew);
}
void EpollerPoller::fillActiveChannels(int numEvents,
                                ChannelList* activeChannels) {
    for(int i = 0; i < numEvents; i++) {
       Channel* channel = static_cast<Channel*> (events_[i].data.ptr); 
       /* 收集发生事件的channel */
       channel->set_revents(events_[i].events);
       activeChannels->push_bush(channel);
    }
}
/* 跟新channel 通道 epoll_ctl add/mod/del */
void EpollerPoller::update(int operation,Channel* channel) {
    struct epoll_event event;
    int fd = channel->fd();
    memset(&event,0,sizeof(event));
    event.events = channel->events();
    event.data.ptr = channel;
    event.data.fd = fd;

    if(::epoll_ctl(epollfd_,operation,fd,&event)< 0) {
        if(operation == EPOLL_CTL_DEL) {
            printf("epoll_ctl_del error  \n");
        }else {
            
        }
    }
}