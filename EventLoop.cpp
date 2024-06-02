/*
 * @Author: abin
 * @Date: 2024-05-28 01:03:12
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-06-02 20:48:01
 * @FilePath: /github/EventLoop.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#include <sys/eventfd.h>
#include "EventLoop.h"
#include <unistd.h>
#include <fcntl.h>
#include "Channel.h"
#include <mutex>
class EventLoop;
/* 防止一个线程创建多个eventloop */
/* __thread 有thread_local,每一个线程只有一个t_loopInThisThread */
inline __thread EventLoop* t_loopInThisThread = nullptr;
/* 定义默认的poller IO 复用接口的超时时间 */
const int kPollTimeMs = 10000;
/* 创建 wakeupfd,用来notify 唤醒subReaactor 处理新来的 channel */
int createEventfd()
{
    int evtfd =::eventfd(0,EFD_NONBLOCK |EFD_CLOECEC);
    if(evtfd < 0) {
        printf(" 通知不下去啊\n");
    }
    return evtfd;   
}
EventLoop::EventLoop()
    :looping_(false)
    ,quit_(false)
    ,callingPendingFunctors_(false)
    ,threadId_(CurrentThread::tid())
    ,poller_(Poller::newDefaultPoller(this))
    ,wakeupFd_(createEventfd())
    ,wakeupChannel_(new Channel(this,wakeupFd))
    ,currentActiveChannel_(nullptr) {
        printf("EventLoop 启动 \n");
        if(t_loopInThisThread) {
            printf("当前线程不为空 \n");
        } else {
            t_loopInThisThread = this;
        }
        /* 设置wakeupfd的事件类型以及发生事件后的回调操作 */
        wakeupChannel_->setReadCallback(std::bind(&Eventloop::handleRead,this));
        /* 每个eventloop 都将监听wakeupChannel 的EPOLLIN 读事件 */
        wakeupChannel_->enableReading();
    
}     

EventLoop::~EventLoop() {
    wakeupChannel_->disableAll();
    wakeupChannel_->remove();
    ::close(wakeupFd_);
    t_loopInThisThread = nullptr;
}

void Eventloop::handleRead() {
    uint64_t one = 1;
    size_t n = read(wakeupFd_,&one,sizeof(one));
    if(n != sizeof(one)) {
         
    }
}
/* 开启循环事件 一个loop 是一个线程*/
void EventLoop::loop() {
    looping_ = true;
    quit_ = false;
    while(!quit_) {
        activeChannels_.clear();
        pollReturnTime_ = poller_->poll(kPollTimeMs,&activeChannels_);
        for(Channel* channel: activeChannels_) {
            /* poller 监听那些channel发生事件了,然后上报给
eventLoop,通知channel 处理相应的事件
            */
            channel->handleEvent(pollReturnTime);
            /* 执行当前EventLoop 事件循环需要处理的回调事件*/
            /*
            IO 线程 mainLoop accept返回 fd 《《==channel subloop
            mainLoop 实现注册一个回调cd 
            */
            doPendingFunctors();
       }
    } 


}
/* 退出循环事件 */
void EventLoop::quit() {
    quit_ = true;
    /* 如果是在其他线程中调用quit,在subloop 中，调用了mainLoop 的quit */
    if(!isInLoopThread()) {
        wakeup();
    }
}

/* 在当前loop 中执行cb */
void EventLoop::runInLoop(Function f) {
    if(isInLoopThread()) { /* 在当前的loop 线程中执行f */
        f();
    }else {
        /* 在非当前loop 线程中执行f,就需要唤醒所有线程，执行f */
        queueInLoop(f);
    }
}

void EventLoop::queueInLoop(function f) {
    {
        std::unique_lock<std::mutex> lock(mutex_);
        pendingFunction_emplace_back(f);
    }
    // 唤醒相应的，需要执行回调操作的loop的线程了
    if(!isInLoopThread()) {
        wakeup(); // 唤醒loop所在线程 
    }
}