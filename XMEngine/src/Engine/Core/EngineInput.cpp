//
//  EngineInput.cpp
//  XMEngine
//
//  Created by thezzk on 17/2/10.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "EngineInput.h"
#include "EngineCore.h"
namespace gEngine
{
    void Input::initialize()
    {
        for(int i = 0; i <= GLFW_KEY_LAST; i++)
        {
            mKeyPreviousState[i] = false;
            mIsKeyPressed[i] = false;
            mIsKeyClicked[i] = false;
        }
        // set callback
        glfwSetKeyCallback((Core::getInstance())->getGLWindow(), keyCallback);
    }
    void Input::update()
    {
        for(int i = 0; i <= GLFW_KEY_LAST; i++)
        {
            mIsKeyClicked[i] = (!mKeyPreviousState[i]) && mIsKeyPressed[i];
            mKeyPreviousState[i] = mIsKeyPressed[i];
        }
    }
    
    // For Gameplay programmer to test if a key is pressed
    bool Input::isKeyPressed(int keyCode)
    {
        return mIsKeyPressed[keyCode];
    }
    bool Input::isKeyClicked(int keyCode)
    {
        return mIsKeyClicked[keyCode];
    }
}// namespace gEngine