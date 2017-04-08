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
    (gEngine::AudioClips::getInstance())->stopBackgroundAudio();
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
    mPortal = std::shared_ptr<gEngine::SpriteRenderable>(new gEngine::SpriteRenderable(kMinionSprite));
    mPortal->setColor({1.0f, 0.0f, 0.0f, 0.2f});
    mPortal->getXform().setPosition(25.0f, 60.0f);
    mPortal->getXform().setSize(3.0f, 3.0f);
    mPortal->setElementPixelPositions(130, 310, 0, 180);
    
    mCollector = std::shared_ptr<gEngine::SpriteRenderable>(new gEngine::SpriteRenderable(kMinionSprite));
    mCollector->setColor({0.0f, 0.0f, 0.0f, 0.0f});
    mCollector->getXform().setPosition(15.0f, 60.0f);
    mCollector->getXform().setSize(3.0f, 3.0f);
    mCollector->setElementPixelPositions(315, 495, 0, 180);
    //C: Create the font and so
    mFontImage = std::shared_ptr<gEngine::SpriteRenderable>(new gEngine::SpriteRenderable(kFontImage));
    mFontImage->setColor({1.0f, 1.0f, 1.0f, 0.0f});
    mFontImage->getXform().setPosition(13.0f, 62.0f);
    mFontImage->getXform().setSize(4.0f, 4.0f);
    
    mMinion = std::shared_ptr<gEngine::SpriteRenderable>(new gEngine::SpriteRenderable(kMinionSprite));
    mMinion->setColor({1.0f, 1.0f, 1.0f, 0.0f});
    mMinion->getXform().setPosition(26.0f, 56.0f);
    mMinion->getXform().setSize(5.0f, 2.5f);
    
    //D: Hero is here
    mHero = std::shared_ptr<gEngine::SpriteRenderable>(new gEngine::SpriteRenderable(kMinionSprite));
    mHero->setColor({1.0f, 1.0f, 1.0f, 0.0f});
    mHero->getXform().setPosition(20.0f, 60.0f);
    mHero->getXform().setSize(2.0f, 3.0f);
    mHero->setElementPixelPositions(0, 120, 0, 180);
    
    (gEngine::AudioClips::getInstance())->playBackgroundAudio(kBgClip);
}
void MyGame::update()
{
    GLfloat deltaX = 0.05;
    gEngine::Transform& xform = mHero->getXform();
    
    //support hero movement
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_D))
    {
        xform.incXPosBy(deltaX);
        if(xform.getXPos() > 30.0f)
            xform.setPosition(12.0f, 60.0f);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_A))
    {
        xform.incXPosBy(-deltaX);
        if(xform.getXPos() < 11.0f)
            xform.setXPos(20.0f);
    }
    
    //continously change texture tinting
    std::vector<GLfloat> c = mPortal->getColor();
    GLfloat ca = c[3] +  deltaX;
    if(ca > 1) ca = 0.0f;
    
    GLfloat deltaT = 0.001f;
    std::vector<GLfloat> texCoord = mFontImage->getElementUVCoordinateArray();
    GLfloat b = texCoord[gEngine::SpriteRenderable::SPRITE_BOTTOM] + deltaT;
    GLfloat r = texCoord[gEngine::SpriteRenderable::SPRITE_RIGHT] - deltaT;
    if(b > 1.0) b = 0;
    if(r < 0) r = 1.0f;
    mFontImage->setElementUVCoordinate(texCoord[gEngine::SpriteRenderable::SPRITE_LEFT], r, b, texCoord[gEngine::SpriteRenderable::SPRITE_TOP]);
    
    
    texCoord = mMinion->getElementUVCoordinateArray();
    GLfloat t = texCoord[gEngine::SpriteRenderable::SPRITE_TOP] - deltaT;
    GLfloat l = texCoord[gEngine::SpriteRenderable::SPRITE_LEFT] + deltaT;
    
    if(l > 0.5f) l = 0;
    if(t < 0.5f) t = 1.0f;
    mMinion->setElementUVCoordinate(l, texCoord[gEngine::SpriteRenderable::SPRITE_RIGHT], texCoord[gEngine::SpriteRenderable::SPRITE_BOTTOM], t);
}
void MyGame::draw()
{
    //A: clear the canvas
    (gEngine::Core::getInstance())->clearCanvas({0.9, 0.9, 0.9, 1.0});
    //B: Activate the drawing Camera
    mCamera->setupViewProjection();
    //C: Draw all objs
    mCollector->draw(mCamera->getVPMatrix());
    mPortal->draw(mCamera->getVPMatrix());
    mHero->draw(mCamera->getVPMatrix());
    mMinion->draw(mCamera->getVPMatrix());
    mFontImage->draw(mCamera->getVPMatrix());
    
}
