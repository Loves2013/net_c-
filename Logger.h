/*
 * @Author: abin
 * @Date: 2024-05-27 01:51:23
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-28 00:46:21
 * @FilePath: /github/Logger.h
 * @Description: 日志级别 INFO ERROR FATAL DEBUG
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
 #ifndef MUDUO_LOGGER_H
 #define MUDUO_LOGGER_H

#include "noncopyable.h"
#include <string>

namespace muduo {

/* LOG_INFO (%s %d,arg1, arg2) */
#define LOG_INFO(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance();\
        logger.setLogLevel(INFO);\
        char buf[1024] = {0};\
        snprintf(buf,1024,logmsgFormat,##__VA_ARGS__);\
    } while(0)
    
enum LogLevel 
{
    INFO,   // 普通信息
    ERROR,  // 错误信息
    FATAL,  // core信息
    DEBUG,  // 调试信息
};
/* 输出一个日志类 */
class Logger : noncopyable {
public:
    /* 获取日志唯一的实例对象 */
    static Logger& instance();
    /* 设置日志级别 */
    void setLogLevel(int level);
    /* 写日志 */
    void log(std::string msg);
    ~Logger(){}

private:  
    int logLevel_;
    
};
}

#endif // 