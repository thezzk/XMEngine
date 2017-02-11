//
//  EngineInput.hpp
//  XMEngine
//
//  Created by thezzk on 17/2/10.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef EngineInput_hpp
#define EngineInput_hpp

#include <stdio.h>
#include <map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "SingletonBase.h"
#include "KeycodeDef.h"

namespace gEngine
{
    
class Input:public SingletonBase<Input>
{
public:
    friend SingletonBase<Input>;
    void initialize();
    void update();
    bool isKeyPressed(int keyCode);
    bool isKeyClicked(int keyCode);
    
private:
    /*Singleton pattern support*/
    Input(){}
    Input(const Input&){}
    Input &operator=(const Input&);
    /*-------------------------*/
    
    bool mKeyPreviousState[GLFW_KEY_LAST+1];
    bool mIsKeyPressed[GLFW_KEY_LAST+1];
    bool mIsKeyClicked[GLFW_KEY_LAST+1];
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        Input* instance = Input::getInstance();
        if(action == GLFW_PRESS)
        {
            instance->mIsKeyPressed[key] = true;
            
        }
        if(action == GLFW_RELEASE)
        {
            instance->mIsKeyPressed[key] = false;
            
        }
        
    }
    
};
    
    
}// namespace gEngine
#endif /* EngineInput_hpp */
