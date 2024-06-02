/*
 * @Author: abin
 * @Date: 2024-06-02 17:09:19
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-06-02 17:13:20
 * @FilePath: /github/CurrentThread.h
 * @Description: 
 * 
 * Copyright (c) 2024 by 17320066637@163.com, All Rights Reserved. 
 */
 
namespace CurrentThread {
    inline __thread int t_cachedTid = 0;
    
    void cacheTid();
    inline int tid() {
        if(__builtin_expect(t_cachedTid == 0,0)) {
            cacheTid();
        }
        return t_cachedTid;
    }
}