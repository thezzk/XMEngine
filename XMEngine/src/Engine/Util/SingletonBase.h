//
//  SingletonBase.h
//  XMEngine
//
//  Created by thezzk on 17/1/19.
//  Copyright © 2017年 thezzk. All rights reserved.
//
#include <mutex>

#ifndef SingletonBase_h
#define SingletonBase_h

template<typename T>
class SingletonBase
{
public:
    static T* getInstance()
    {
        mMutex.lock();
        if(NULL != mInstance)
        {
            mMutex.unlock();
            return mInstance;
        }
        mInstance = new T();
        mMutex.unlock();
        return mInstance;
    }
    SingletonBase(){}
    virtual ~SingletonBase(){}
private:
    static T* mInstance;
    static std::mutex mMutex;
};

template<typename T>
T* SingletonBase<T>::mInstance = NULL;
template<typename T>
std::mutex SingletonBase<T>::mMutex;

#endif /* SingletonBase_h */