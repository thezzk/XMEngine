//
//  MyGame.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef MyGame_hpp
#define MyGame_hpp

#include "iostream"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "SimpleShader.h"
#include "Renderable.h"
#include "Camera.h"

class MyGame
{
private:
    gEngine::SimpleShader *mConstColorShader;
    gEngine::Renderable *mBlueSq;
    gEngine::Renderable *mRedSq;
    gEngine::Renderable *mTLSq;
    gEngine::Renderable *mTRSq;
    gEngine::Renderable *mBRSq;
    gEngine::Renderable *mBLSq;
    gEngine::Camera mCamera;
    
public:
    MyGame();
    ~MyGame();
    
};
#endif /* MyGame_hpp */
