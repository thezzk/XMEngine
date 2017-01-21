//
//  SingletonBase.h
//  XMEngine
//
//  Created by thezzk on 17/1/19.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef SingletonBase_h
#define SingletonBase_h

template<typename T>
class SingletonBase
{
public:
    static T* getInstance()
    {
        if(NULL != mInstance)
        {
            return mInstance;
        }
        mInstance = new T();
        return mInstance;
    }
    SingletonBase(){}
    virtual ~SingletonBase(){}
private:
    static T* mInstance;
};

template<typename T>
T* SingletonBase<T>::mInstance = NULL;


#endif /* SingletonBase_h */