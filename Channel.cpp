/*
 * @Author: abin
 * @Date: 2024-05-28 01:23:57
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-28 14:03:30
 * @FilePath: /github/Channel.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#include "Channel.h"
#include "EventLoop.h"
#include <sstream>
#include <sys/epoll.h>
#include "Timestamp.h"


const int Channel::kNoneEvent_ = 0;
const int Channel::kReadEvent_ = EPOLLIN | EPOLLPRI;
const int Channel::kWriteEvent_ = EPOLLOUT;

Channel::Channel(EventLoop* loop,int fd) 
    : loop_(loop), fd_(fd), events_(0), revents_(0), index_(-1), tied_(false)
{
    

}
Channel::~Channel() {
    
}

void Channel::tie(const std::shared_ptr<void> &obj) 
{
    tie_ = obj;
    tied_ = true;
}
/* 当改变channel所表示fd的events事件后，update 负责在poller里面更改fd相应的事件epoll_ctl*/
void Channel::update() 
{
    /* 通过channel 所属的EventLoop 调用poller 相应的方法， 注册fd 的events事件 */
    
}

/*  在channel 所属的Eventpool 中，当前的channel 删除掉 */
void Channel::remove() {
   // loop_->removeChannel(this);
}
/* fd 得到了poller 通知以后，处理事件的 */
void Channel::handleEvent(Timestamp* receiveTime) {
    if(tied_) {
        std::shared_ptr<void> guard = tie_.lock();
        if(guard) {
            handleEventWithGuard(receiveTime);
        }
    }else
    {
        handleEventWithGuard(receiveTime);
    }
}
/* 根据poller 通知在channel 发生的具体事件 
    由channel负责调用具体的回调操作
*/
void Channel::handleEventWithGuard(Timestamp* receiveTime) {
    if((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN)) {
        if(closeCallback_) {
            closeCallback_();
        }
    }

    if(revents_ & EPOLLERR) {
        if(errorCallback_) {
            errorCallback_();
        }
    } 
    if(revents_ & (EPOLLIN | EPOLLPRI)) {
        if(readCallback_) {
            //
            readCallback_();
        }
    }
    if(revents_ & EPOLLOUT) {
       if(writeCallback_) {
        writeCallback_();
       } 
    }
}