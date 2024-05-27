/*
 * @Author: abin
 * @Date: 2024-05-27 13:39:33
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-27 13:44:22
 * @FilePath: /github/Timestamp.h
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#ifndef MUDUO_TIMESTAMP_H
#define MUDUO_TIMESTAMP_H
#include <iostream>
#include <string>
namespace muduo {
class Timestamp {
public:
    Timestamp();
    Timestamp(int64_t microSecondsSinceEpoch);
    static Timestamp now();
    std::string toString() const;
private:
    int64_t microSecondsSinceEpoch_;

};

}
#endif // !MUDUO_TIMESTAMP_H