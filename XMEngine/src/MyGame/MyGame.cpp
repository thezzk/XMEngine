//
//  MyGame.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "MyGame.h"
#include "EngineCore.h"

MyGame::MyGame()
{
    (gEngine::Core::getInstance())->initializeGL();
    this->mShader = new gEngine::SimpleShader("/Users/thezzk/Develop/MEngine/XMEngine/XMEngine/XMEngine/src/SimpleVS.glsl", "/Users/thezzk/Develop/MEngine/XMEngine/XMEngine/XMEngine/src/WhiteFS.glsl");
    
    //C1: Clear the canvas
    (gEngine::Core::getInstance())->clearCanvas({0, 0.8, 0, 1});
    
    //C2: Activate the proper shader
    this->mShader->activateShader();
    
    //C3: Draw with the currently activated geometry and the activated shader
    GLFWwindow* window = (gEngine::Core::getInstance())->getGLWindow();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glfwSwapBuffers(window);
    glfwPollEvents();
}
MyGame::~MyGame()
{
    delete mShader;
}