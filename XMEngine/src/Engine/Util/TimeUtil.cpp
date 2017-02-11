//
//  TimeUtil.cpp
//  XMEngine
//
//  Created by thezzk on 17/2/7.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "TimeUtil.h"
#include <ctime>

TimeUtil::TimeUtil()
{
    gettimeofday(&startTime, NULL);
}

unsigned long TimeUtil::getMillisecond()
{
    timeval mtime;
    gettimeofday(&mtime, NULL);
    unsigned long retval = (mtime.tv_sec - startTime.tv_sec) * 1000 + (mtime.tv_usec - startTime.tv_usec) / 1000;
    return retval;
}