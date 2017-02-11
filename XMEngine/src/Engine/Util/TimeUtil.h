//
//  TimeUtil.hpp
//  XMEngine
//
//  Created by thezzk on 17/2/7.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef TimeUtil_hpp
#define TimeUtil_hpp

#include <stdio.h>
#include "sys/time.h"
#include "SingletonBase.h"

class TimeUtil: public SingletonBase<TimeUtil>
{
public:
    friend SingletonBase<TimeUtil>;
    unsigned long getMillisecond();
private:
    /*Singleton pattern support*/
    TimeUtil();
    TimeUtil(const TimeUtil&){}
    TimeUtil &operator=(const TimeUtil&);
    /*-------------------------*/
    timeval startTime;
    
    
};
#endif /* TimeUtil_hpp */
