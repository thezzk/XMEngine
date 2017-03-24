//
//  BlueLevel.cpp
//  XMEngine
//
//  Created by thezzk on 17/3/19.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "BlueLevel.h"
#include "TextFileLoader.h"
#include "SceneFileParser.h"
#include "EngineInput.h"
#include "EngineGameLoop.h"
#include "EngineCore.h"
#include "AudioClips.h"

BlueLevel::BlueLevel()
{
    
}
BlueLevel::~BlueLevel()
{
    
}

void BlueLevel::loadScene()
{
    (gEngine::TextFileLoader::getInstance())->loadTextFile(kSceneFile, gEngine::TextFileLoader::E_XML_FILE);
    (gEngine::AudioClips::getInstance())->loadAudio(kBgClip);
    (gEngine::AudioClips::getInstance())->loadAudio(kCue);
}

void BlueLevel::initialize()
{
    gEngine::SceneFileParser sceneFileParser(kSceneFile);
    //A: Camera
    mCamera = sceneFileParser.parseCamera();
    //B: Squares
    mSqSet = sceneFileParser.parseSquares();
    
    (gEngine::AudioClips::getInstance())->playBackgroundAudio(kBgClip);
}

void BlueLevel::update()
{
    //A: white square
    gEngine::Transform& whiteXform = mSqSet[0]->getXform();
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_D))
    {
        if(whiteXform.getXPos() > 30.0f)
        {
            whiteXform.setPosition(10.0f, 60.0f);
        }
        (gEngine::AudioClips::getInstance())->playACue(kCue);
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
    
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_A))
    {
        (gEngine::AudioClips::getInstance())->playACue(kCue);
        redXform.incXPosBy(-0.05f);
        if(redXform.getXPos() < 11.0f)
        {
            (gEngine::GameLoop::getInstance())->stop();
        }
    }
    
}

void BlueLevel::unloadScene()
{
    //Stop BGM
    (gEngine::AudioClips::getInstance())->stopBackgroundAudio();
    
    (gEngine::AudioClips::getInstance())->unloadAudio(kBgClip);
    (gEngine::AudioClips::getInstance())->unloadAudio(kCue);
    (gEngine::TextFileLoader::getInstance())->loadTextFile(kSceneFile, gEngine::TextFileLoader::E_XML_FILE);
    std::shared_ptr<Scene> nextLevel(new MyGame());
    (gEngine::Core::getInstance())->startScene(nextLevel);
}

void BlueLevel::draw()
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

