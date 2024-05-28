/*
 * @Author: abin
 * @Date: 2024-05-28 01:23:46
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-28 13:25:23
 * @FilePath: /github/Channel.h
 * @Description: 
 * Channel 理解为通道,分装了sockfd和感兴趣的event，如EPOLLIN,EPOLLOUT的事件
 * 理清楚 EventLoop Channel Poller 之间的关系<=Reactor 模型上
 * 对应 Demultiplex
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#pragma once
#include <unistd.h>
#include <string>
#include <iostream>
#include <functional>
#include "Timestamp.h"
#include <memory>
class EventLoop;  /* 头文件的前置声明 */
class Timestamp;
class TcpServer;
class Channel {
public:
    typedef std::function<void()> EventCallback;  /* 事件回调*/
    typedef std::function<void()> ReadEventCallback; /* 只读事件的回调 */

    Channel(EventLoop* loop,int fd);
    ~Channel();
    /* fd 得到poller 通知以后，处理事件 */
    void handleEvent(Timestamp* receiveTime);

    /* 设置回调函数对象 */
    void setReadCallback(ReadEventCallback callback) {
        readCallback_ = std::move(callback);
    } 

    void setWriteCallback(EventCallback callback) {
        writeCallback_ = std::move(callback);
    }

    void setCloseCallback(EventCallback callback) {
        closeCallback_ = std::move(callback);
    }

    void setErrorCallback(EventCallback callback) {
         errorCallback_ = std::move(callback);
    }

    /* 防止当channel 被手动remove掉， channel 还在执行回调操作 */
    void tie(const std::shared_ptr<void>&);

    int fd() const { return fd_; }
    int events() const { return events_;}
    void set_revents(int revt) { revents_ = revt; }
    /* 判断 events_ 有没有注册感兴趣的事件 */
    bool isNoneEvent() const { return events_ == kNoneEvent_;}

    void enableReading() { events_ |= kReadEvent_; update();   }
    void disableReading() { events_ &= ~kReadEvent_; update(); } 
    void enabeleWriting() { events_ |= kWriteEvent_; update(); }
    void disableWriting() { events_ &= ~kWriteEvent_; update(); }
    void disableAll() { events_ = kNoneEvent_; update(); }

    // 返回fd 当前的事件状态
    bool isNoneEvent() const { return events_ == kNoneEvent_; }
    bool isWriting() const { return events_ & kWriteEvent_; }
    bool isReading() const { return events_ & kReadEvent_; }

    int index() { return index_; }
    void set_index(int index) { index_ = index; }
    /* 每个线程一个循环 */
    EventLoop* ownerLoop() { return loop_;}

    void remove();
    

private:
    void update();
    void handleEventWithGuard(Timestamp* receiveTime);


    static const int kNoneEvent_;   /* 没事件 */
    static const int kReadEvent_;   /* 读事件 */
    static const int kWriteEvent_;  /* 写事件感兴趣*/

    EventLoop* loop_;   /* 事件循环 */
    const int fd_;      /* fd， Poller 监听的对象 */
    int events_;        /* 注册fd感兴趣的事件 */
    int revents_;      /* poller 返回的具体发生的事件 */
    int index_;
    std::weak_ptr<void> tie_;
    bool tied_;
    /* 因为Channel 通道里面能够获取fd 最终发生的具体的事件revents 所以它负责调用
    具体事件的回调操作  */
    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback closeCallback_;
    EventCallback errorCallback_;

};