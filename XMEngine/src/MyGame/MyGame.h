//
//  MyGame.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef MyGame_hpp
#define MyGame_hpp

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "SimpleShader.h"

class MyGame
{
private:
     gEngine::SimpleShader* mShader;
public:
    MyGame();
    ~MyGame();
    
};
#endif /* MyGame_hpp */
