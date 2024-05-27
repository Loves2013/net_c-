/*
 * @Author: abin
 * @Date: 2024-05-27 13:39:44
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-05-27 14:04:48
 * @FilePath: /github/Timestamp.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
#include "Timestamp.h"
#include <time.h>
namespace muduo {
Timestamp::Timestamp():microSecondsSinceEpoch_(0){

};
/* explicit 防止隐式转换 */
explicit Timestamp::Timestamp(int64_t microSecondsSinceEpoch)
    :microSecondsSinceEpoch_(microSecondsSinceEpoch) {
    
}

Timestamp Timestamp::now() {
   return Timestamp(time(NULL));
}

std::string Timestamp::toString() const {
    char buf[128] = {0};
    tm* tm_time = localtime(&microSecondsSinceEpoch_);
    snprintf(buf,128,"%4d/%02d/%02d %02d:%02d:%02d",
    tm_time->tm_yday+1900,
    tm_time->tm_mon +1,
    tm_time->tm_mday,
    tm_time->tm_hour,
    tm_time->tm_min,
    tm_time->tm_sec);
     return buf;
}

}

