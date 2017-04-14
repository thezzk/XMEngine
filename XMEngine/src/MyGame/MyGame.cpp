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
#include "EngineFonts.h"
#include <stdlib.h>
#include "cstring"
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
    
    (gEngine::Fonts::getInstance())->loadFont(kFontCon16);
    (gEngine::Fonts::getInstance())->loadFont(kFontCon24);
    (gEngine::Fonts::getInstance())->loadFont(kFontCon32);
    (gEngine::Fonts::getInstance())->loadFont(kFontCon72);
    (gEngine::Fonts::getInstance())->loadFont(kFontSeg96);
    
    
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
    
    (gEngine::Fonts::getInstance())->unloadFont(kFontCon16);
    (gEngine::Fonts::getInstance())->unloadFont(kFontCon32);
    (gEngine::Fonts::getInstance())->unloadFont(kFontCon24);
    (gEngine::Fonts::getInstance())->unloadFont(kFontCon72);
    (gEngine::Fonts::getInstance())->unloadFont(kFontSeg96);
    
    std::shared_ptr<Scene> nextLevel(new BlueLevel());
    (gEngine::Core::getInstance())->startScene(nextLevel);

}
void MyGame::initialize()
{
   
    //A: Camera
    mCamera = std::shared_ptr<gEngine::Camera>(new gEngine::Camera(glm::vec2(50.0f, 30.0f), 160.0f, std::vector<GLfloat>({20.0f, 40.0f, 600.0f, 300.0f})));
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
    //C: fonts
    mTextSysFont = std::shared_ptr<gEngine::FontRenderable>(new gEngine::FontRenderable("System Font: in Red"));
    initText(mTextSysFont, 50.0f, 60.0f, {1.0f, 0.0f, 0.0f, 1.0f}, 3.0f);
    
    mTextCon16 = std::shared_ptr<gEngine::FontRenderable>(new gEngine::FontRenderable("Consolas 16: in black"));
    mTextCon16->setFont(kFontCon16);
    initText(mTextCon16, 50.0f, 55.0f, {0.0f, 0.0f, 0.0f, 1.0f}, 2.0f);
    
    mTextCon24 = std::shared_ptr<gEngine::FontRenderable>(new gEngine::FontRenderable("Consolas 24: in black"));
    mTextCon24->setFont(kFontCon24);
    initText(mTextCon24, 50.0f, 50.0f, {0.0f, 0.0f, 0.0f, 1.0f}, 3.0f);
    
    mTextCon32 = std::shared_ptr<gEngine::FontRenderable>(new gEngine::FontRenderable("Consolas 32: in white"));
    mTextCon32->setFont(kFontCon32);
    initText(mTextCon32, 40.0f, 40.0f, {1.0f, 1.0f, 1.0f, 1.0f}, 4.0f);
    
    mTextCon72 = std::shared_ptr<gEngine::FontRenderable>(new gEngine::FontRenderable("Consolas 72: in blue"));
    mTextCon72->setFont(kFontCon72);
    initText(mTextCon72, 30.0f, 30.0f, {0.0f, 0.0f, 1.0f, 1.0f}, 6.0f);
    
    mTextSeg96 = std::shared_ptr<gEngine::FontRenderable>(new gEngine::FontRenderable("Segment7-92"));
    mTextSeg96->setFont(kFontSeg96);
    initText(mTextSeg96, 30.0f, 15.0f, {1.0f, 1.0f, 0.0f, 1.0f}, 7.0f);
    
    mTextToWork = mTextCon16;
    //(gEngine::AudioClips::getInstance())->playBackgroundAudio(kBgClip);
}
void MyGame::update()
{
    /*mRightMinion->updateAnimation();
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
    */
    if((gEngine::Input::getInstance())->isKeyClicked(KEY_0))
    {
        mTextCon16->setText("click0");
    }
    if((gEngine::Input::getInstance())->isKeyClicked(KEY_Q))
    {
        (mTextCon24->getXform()).incHeightBy(0.05f);
        GLfloat w = (mTextCon24->getXform()).getWidth();
        GLfloat h = (mTextCon24->getXform()).getHeight();
        std::stringstream ss;
        ss<<w<<" x "<<h;
        mTextCon24->setText(ss.str().c_str());
        
    }
    if((gEngine::Input::getInstance())->isKeyClicked(KEY_E))
    {
        (mTextCon24->getXform()).incWidthBy(-0.05f);
        GLfloat w = (mTextCon24->getXform()).getWidth();
        GLfloat h = (mTextCon24->getXform()).getHeight();
        std::stringstream ss;
        ss<<w<<" x "<<h;
        mTextCon24->setText(ss.str().c_str());
    }
    
   
}
void MyGame::draw()
{
    //A: clear the canvas
    (gEngine::Core::getInstance())->clearCanvas({0.9, 0.9, 0.9, 1.0});
    //B: Activate the drawing Camera
    mCamera->setupViewProjection();
    //C: Draw all objs
    //mLeftMinion->draw(mCamera->getVPMatrix());
    //mRightMinion->draw(mCamera->getVPMatrix());
    //D: Draw fonts
    mTextSysFont->draw(mCamera->getVPMatrix());
    mTextCon16->draw(mCamera->getVPMatrix());
    mTextCon32->draw(mCamera->getVPMatrix());
    mTextCon24->draw(mCamera->getVPMatrix());
    mTextCon72->draw(mCamera->getVPMatrix());
    mTextSeg96->draw(mCamera->getVPMatrix());
  
    
}

void MyGame::initText(std::shared_ptr<gEngine::FontRenderable> font, GLfloat posX, GLfloat posY, std::vector<GLfloat> color, GLfloat textH)
{
    font->setColor(color);
    (font->getXform()).setPosition(posX, posY);
    font->setTextHeight(textH);
}
