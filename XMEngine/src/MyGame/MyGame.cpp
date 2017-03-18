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
#include "SceneFileParser.h"
#include "TextFileLoader.h"
#include <glm/gtc/matrix_transform.hpp>

MyGame::MyGame()
{
    
}
MyGame::~MyGame()
{
    
}
void MyGame::loadScene()
{
    (gEngine::TextFileLoader::getInstance())->loadTextFile(kSceneFile, gEngine::TextFileLoader::E_XML_FILE);
}
void MyGame::unloadScene()
{
    (gEngine::TextFileLoader::getInstance())->unloadTextFile(kSceneFile);
}
void MyGame::initialize()
{
    gEngine::SceneFileParser sceneFileParser(kSceneFile);
    //A: Camera
    mCamera = sceneFileParser.parseCamera();
    //B: Squares
    mSqSet = sceneFileParser.parseSquares();
}
void MyGame::update()
{
    //A: white square
    gEngine::Transform& whiteXform = mSqSet[0]->getXform();
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
    gEngine::Transform& redXform = mSqSet[1]->getXform();
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
    mCamera->setupViewProjection();
    //C: Draw all squares
    for(int i = 0; i < mSqSet.size(); i++)
    {
        mSqSet[i]->draw(mCamera->getVPMatrix());
    }
    
}

