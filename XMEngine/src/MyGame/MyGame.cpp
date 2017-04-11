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
#include "BlueLevel.h"
#include "AudioClips.h"
#include "EngineTexture.h"
#include "SpriteRenderable.h"
MyGame::MyGame()
{
    
}
MyGame::~MyGame()
{
    
}
void MyGame::loadScene()
{
    (gEngine::Textures::getInstance())->loadTexture(kMinionSprite);
    (gEngine::Textures::getInstance())->loadTexture(kFontImage);
    
    (gEngine::AudioClips::getInstance())->loadAudio(kBgClip);
    (gEngine::AudioClips::getInstance())->loadAudio(kCue);
}
void MyGame::unloadScene()
{
    //Stop BGM
    //(gEngine::AudioClips::getInstance())->stopBackgroundAudio();
    //(gEngine::AudioClips::getInstance())->unloadAudio(kBgClip);
    //The above line is commented out because the BGM clip will use in the next level!
    (gEngine::AudioClips::getInstance())->unloadAudio(kCue);
    
    (gEngine::Textures::getInstance())->unloadTexture(kFontImage);
    (gEngine::Textures::getInstance())->unloadTexture(kMinionSprite);
    std::shared_ptr<Scene> nextLevel(new BlueLevel());
    (gEngine::Core::getInstance())->startScene(nextLevel);

}
void MyGame::initialize()
{
   
    //A: Camera
    mCamera = std::shared_ptr<gEngine::Camera>(new gEngine::Camera(glm::vec2(20.0f, 60.0f), 20.0f, std::vector<GLfloat>({20.0f, 40.0f, 600.0f, 300.0f})));
    mCamera->setBackgroundColor({0.8f, 0.8f, 0.8f, 1.0f});
    //B: GameObjs
    mRightMinion = std::shared_ptr<gEngine::SpriteAnimateRenderable>(new gEngine::SpriteAnimateRenderable(kMinionSprite));
    mRightMinion->setColor({1.0f, 1.0f, 1.0f, 0.0f});
    mRightMinion->getXform().setPosition(26.0f, 56.5f);
    mRightMinion->getXform().setSize(4.0f, 3.2f);
    mRightMinion->setSpriteSequence(512, 0, 204, 164, 5, 0);
    mRightMinion->setAnimationType(gEngine::SpriteAnimateRenderable::ANIMATE_RIGHT);
    mRightMinion->setAnimationInterval(50);
    
    mLeftMinion = std::shared_ptr<gEngine::SpriteAnimateRenderable>(new gEngine::SpriteAnimateRenderable(kMinionSprite));
    mLeftMinion->setColor({1.0f, 1.0f, 1.0f, 0.0f});
    mLeftMinion->getXform().setPosition(15.0f, 56.5f);
    mLeftMinion->getXform().setSize(4.0f, 3.2f);
    mLeftMinion->setSpriteSequence(348, 0, 204, 164, 5, 0);
    mLeftMinion->setAnimationType(gEngine::SpriteAnimateRenderable::ANIMATE_RIGHT);
    mLeftMinion->setAnimationInterval(50);
    
    
    //(gEngine::AudioClips::getInstance())->playBackgroundAudio(kBgClip);
}
void MyGame::update()
{
    mRightMinion->updateAnimation();
    mLeftMinion->updateAnimation();
    if((gEngine::Input::getInstance())->isKeyClicked(KEY_1))
    {
        mRightMinion->setAnimationType(gEngine::SpriteAnimateRenderable::ANIMATE_LEFT);
        mLeftMinion->setAnimationType(gEngine::SpriteAnimateRenderable::ANIMATE_LEFT);
    }
    if((gEngine::Input::getInstance())->isKeyClicked(KEY_2))
    {
        mRightMinion->setAnimationType(gEngine::SpriteAnimateRenderable::ANIMATE_SWING);
        mLeftMinion->setAnimationType(gEngine::SpriteAnimateRenderable::ANIMATE_SWING);
    }
    if((gEngine::Input::getInstance())->isKeyClicked(KEY_3))
    {
        mRightMinion->setAnimationType(gEngine::SpriteAnimateRenderable::ANIMATE_RIGHT);
        mLeftMinion->setAnimationType(gEngine::SpriteAnimateRenderable::ANIMATE_RIGHT);
    }
    if((gEngine::Input::getInstance())->isKeyClicked(KEY_4))
    {
        mRightMinion->incAnimationInterval(-2);
        mLeftMinion->incAnimationInterval(-2);
    }
    if((gEngine::Input::getInstance())->isKeyClicked(KEY_5))
    {
        mRightMinion->incAnimationInterval(2);
        mLeftMinion->incAnimationInterval(2);
    }
    
    
   
}
void MyGame::draw()
{
    //A: clear the canvas
    (gEngine::Core::getInstance())->clearCanvas({0.9, 0.9, 0.9, 1.0});
    //B: Activate the drawing Camera
    mCamera->setupViewProjection();
    //C: Draw all objs
    mLeftMinion->draw(mCamera->getVPMatrix());
    mRightMinion->draw(mCamera->getVPMatrix());
    

    
}
