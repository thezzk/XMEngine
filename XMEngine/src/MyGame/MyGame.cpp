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
#include <glm/gtc/matrix_transform.hpp>

MyGame::MyGame()
{
    //A: Initialize the GL Context
    (gEngine::Core::getInstance())->initializeGL();
    
    //B: Setup the camera
    mCamera = gEngine::Camera(glm::vec2(20.0, 60.0),
                              20.0,
                              {20.0, 40.0, 600.0, 300.0}
    );
    
    //C:Create the shader
    mConstColorShader = new gEngine::SimpleShader("GLSLShaders/SimpleVS.glsl", "GLSLShaders/SimpleFS.glsl");
    
    //D:Create the Renderable objects
    mBlueSq = new gEngine::Renderable(*mConstColorShader);
    mBlueSq->setColor({0.25, 0.25, 0.95, 1});
    mRedSq = new gEngine::Renderable(*mConstColorShader);
    mRedSq->setColor({1, 0.25, 0.25, 1});
    mTLSq = new gEngine::Renderable(*mConstColorShader);
    mTLSq->setColor({0.9, 0.1, 0.1, 1});
    mTRSq = new gEngine::Renderable(*mConstColorShader);
    mTRSq->setColor({0.1, 0.9, 0.1, 1});
    mBRSq = new gEngine::Renderable(*mConstColorShader);
    mBRSq->setColor({0.1, 0.1, 0.9 ,1});
    mBLSq = new gEngine::Renderable(*mConstColorShader);
    mBLSq->setColor({0.1, 0.1, 0.1, 1});
    
    //E:Clear the entrie canvas to be drawn
    (gEngine::Core::getInstance())->clearCanvas({0.9, 0.9, 0.9 ,1});
    
    //F:Starts the drawing by activating the camera
    mCamera.setupViewProjection();
    glm::mat4 vpMatrix = mCamera.getVPMatrix();
    
    //G: Draw the blue square
    mBlueSq->getXform().setPosition(20, 60);
    mBlueSq->getXform().setRotationInRad(0.2);
    mBlueSq->getXform().setSize(5, 5);
    mBlueSq->draw(vpMatrix);
    
    //H: Draw with the red shader
    mRedSq->getXform().setPosition(20, 60);
    mRedSq->getXform().setSize(2, 2);
    mRedSq->draw(vpMatrix);
    
    //top left
    mTLSq->getXform().setPosition(10, 65);
    mTLSq->draw(vpMatrix);
    
    //top right
    mTRSq->getXform().setPosition(30, 65);
    mTRSq->draw(vpMatrix);
    
    //bottom right
    mBRSq->getXform().setPosition(30, 55);
    mBRSq->draw(vpMatrix);
    
    //bottom left
    mBLSq->getXform().setPosition(10, 55);
    mBLSq->draw(vpMatrix);
    
    
}
MyGame::~MyGame()
{
 
}