/*
 * @Author: abin
 * @Date: 2024-05-27 01:51:33
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-27 02:50:07
 * @FilePath: /github/Logger.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#include "Logger.h"
#include <iostream>
namespace muduo {

/* 获取日志唯一的实例对象 */
Logger& Logger::instance() {
    static Logger logger;
    return logger;
}
/* 设置日志 */
void Logger::setLogLevel(int level) {
    logLevel_ = level;
}

//写日志
void Logger::log (std::string msg) {
    switch (logLevel_)
    {
    case INFO:
        std::cout<<"[INFO]";
        break;
    case ERROR:
        std::cout<<"[ERROR]";
    case FATAL:
        std::cout<<"[FATAL]";
    case DEBUG:
        std::cout<<"[DEBUG]";
    default:
        break;
    }

    /* 打印时间和msg */
    std::cout<<"print time "<< " : "<<msg<<std::endl;
}

}