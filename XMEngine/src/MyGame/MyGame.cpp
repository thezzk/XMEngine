//
//  MyGame.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "MyGame.h"
#include "EngineCore.h"
#include "Transform.h"
#include "EngineCore.h"
#include "EngineVertexBuffer.h"
#include "EngineGameLoop.h"
#include "EngineInput.h"
#include "KeycodeDef.h"
#include <glm/gtc/matrix_transform.hpp>

MyGame::MyGame()
{
    //(gEngine::Core::getInstance())->initializeEngineCore();
    //initialize();
}
MyGame::~MyGame()
{
    
}
void MyGame::initialize()
{
    //A: set up cameras
    mCamera=gEngine::Camera(glm::vec2(20, 60), 20, {20, 40, 600, 300});
    mCamera.setBackgroundColor({0.8, 0.8, 0.8, 1});
    //B: create the shader
    mConstColorShader = new gEngine::SimpleShader("GLSLShaders/SimpleVS.glsl", "GLSLShaders/SimpleFS.glsl");
    //C: Create the renderable objects
    mWhiteSq = new gEngine::Renderable(*mConstColorShader);
    mWhiteSq->setColor({1, 1, 1, 1});
    mRedSq = new gEngine::Renderable(*mConstColorShader);
    mRedSq->setColor({1, 0, 0, 1});
    //D: Initialize the white renderable object
    (mWhiteSq->getXform()).setPosition(20.0, 60.0);
    (mWhiteSq->getXform()).setRotationInDegree(90.0f);
    (mWhiteSq->getXform()).setSize(5.0, 5.0);
    //E: Initialize the red renderable object
    (mRedSq->getXform()).setPosition(20.0, 60.0);
    (mRedSq->getXform()).setSize(2.0, 2.0);
}
void MyGame::update()
{
    //A: white square
    gEngine::Transform& whiteXform = mWhiteSq->getXform();
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_D))
    {
        if(whiteXform.getXPos() > 30.0f)
        {
            whiteXform.setPosition(10.0f, 60.0f);
        }
        whiteXform.incXPosBy(0.05f);
    }
    
    if((gEngine::Input::getInstance())->isKeyClicked(KEY_W))
    {
        whiteXform.incRotationByDegree(30.f);
    }
    
    //B: red square
    gEngine::Transform& redXform = mRedSq->getXform();
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_S))
    {
        if(redXform.getWidth() > 5)
            redXform.setSize(2, 2);
        redXform.incSizeBy(0.05);
    }
}
void MyGame::draw()
{
    //A: clear the canvas
    (gEngine::Core::getInstance())->clearCanvas({0.9, 0.9, 0.9, 1.0});
    //B: Activate the drawing Camera
    mCamera.setupViewProjection();
    //C: Activate the white shader to draw
    mWhiteSq->draw(mCamera.getVPMatrix());
    //D: Activate the red shader to draw
    mRedSq->draw(mCamera.getVPMatrix());
    
}

