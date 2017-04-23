//
//  MathExtension.cpp
//  XMEngine
//
//  Created by thezzk on 17/4/22.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "MathExtension.h"
namespace glm
{
    vec2 rotate_2d(vec2 vec, GLfloat rad)
    {
        
        vec2 retval;
        retval[0] = vec[0] * cos(rad) - vec[1] * sin(rad);
        retval[1] = vec[0] * sin(rad) + vec[1] * cos(rad);
        return retval;
    }
}
