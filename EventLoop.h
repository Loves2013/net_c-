/*
 * @Author: abin
 * @Date: 2024-05-28 01:01:14
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-06-02 21:35:28
 * @FilePath: /github/EventLoop.h
 * @Description: 
 * 时间循环类，主要包含了两个大模块，Channel poller（epoll的抽象类）
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */

#include <functional>
#include <cstdio>
#include <vector>
#include <atomic>
#include <memory> 
#include <mutex>
class Channel;
class Poller;
class EventLoop {
public:
    using Function = std::function<void()>;
    EventLoop();
    ~EventLoop();
    void loop() ;/* 开启事件循环 */
    /* 退出事件循环*/
    void quit();
    Timestame pollReturnTime() const{
        return pollReturnTime_;
    }
    //在当前loop 中执行
    void runInLoop(Function f);
    /*把function 放入队列，唤醒loop 所在的线程， 执行f */
    void queueInLoop(Function f);
    /* 来唤醒loop所在的线程*/
    void wakeup();
    /* Eventloop 的方法=》poller 的方法  */
    void updateChannel(Channel* channel);
    void removeChannel(Channel* channel);
    /* 判断EventThread()对象是否在自己的线程里面 */
    bool isInLoopThread() const {
        return threadId_ == CurrentTHread::Tid();
    }

private:
    void handleRead();
    /* 执行回调函数 在vector<Function> 中存放 */
    void dopendingFuncation();
    using ChannelList = std::vector<Channel*>;
    /* 为什么要使用atomic,因为在别的线程中操作*/
    std::atomic_bool looping_;  /*  atomic*/
    std::atomic_bool quit_;     /* 退出loop   */
    const pid_t threadId_;
    Timestamp pollReturnTime_; /* poller 返回发生事件的channels的时间点*/
    std::unique_ptr<Poller> poller_;
    /*主要作用，当mainLoop 获取一个新用户的channel，
    通过轮询算法选择一个subloop,通过该成员唤醒subloop
    处理channel
    */
    int wakeupFd; 
    std::unique_ptr<Channel> wakeupChannel_;
    ChannelList activeChannels_;
    Channel* currentActiveChannel_;

    std::atomic_bool callingPendingFunctors_; /* 标识当前loop是否需要执行回调操作 */
    std::vector<Function> pendingFunctors_; /* 存储loop 需要的执行的所有的回调操作 */
    std::mutex mutex_;  /* 用来保护vector 的线程安全操作 */

};
/* 用来唤醒loop 所有的线程 */
void EventLoop::wakeup() {

}

/* EventLoop的方法=> poller的方法 */
void EventLoop::updateChannel(Channel* channel) {
    poller_->updateChannel(channel);
}
void EventLoop::removeChannel(Channel* channel) {
    poller_->removeChannel(Channel);
}
bool EventLoop::hasChannel(Channel* channel) {

}
void EventLoop::doPendingFunction() {

}