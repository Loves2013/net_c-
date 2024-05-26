/*
 * @Author: abin
 * @Date: 2024-05-27 01:26:47
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-27 01:43:55
 * @FilePath: /github/noncopyable.h
 * @Description: noncopyable 被继承后，派生类对象可以正常析构和构造
 *  但派生类对象无法进行拷贝构造和赋值构造
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#ifndef MUDUO_NONCOPYABLE_H
#define MUDUO_NONCOPYABLE_H
namespace muduo
{

class noncopyable {
public:
    noncopyable(const noncopyable&) = delete;
    noncopyable& operator=(const noncopyable&) = delete;
private:
    noncopyable() = default;
    ~noncopyable() = default;

};
}


#endif