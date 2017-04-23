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
    (gEngine::Textures::getInstance())->loadTexture(kHit);
}
void MyGame::unloadScene()
{
    //Stop BGM
    //(gEngine::AudioClips::getInstance())->stopBackgroundAudio();
    //(gEngine::AudioClips::getInstance())->unloadAudio(kBgClip);
    //The above line is commented out because the BGM clip will use in the next level!
    
    (gEngine::Textures::getInstance())->unloadTexture(kHit);
    
    std::shared_ptr<Scene> nextLevel(new BlueLevel());
    (gEngine::Core::getInstance())->startScene(nextLevel);

}
void MyGame::initialize()
{
   
    //A: Camera
    mCamera = std::shared_ptr<gEngine::Camera>(new gEngine::Camera(glm::vec2(50.0f, 30.0f), 10.0f, std::vector<GLfloat>({20.0f, 40.0f, 600.0f, 300.0f})));
    mCamera->setBackgroundColor({0.8f, 0.8f, 0.8f, 1.0f});
    //B: GameObjs
  
    block = std::shared_ptr<gEngine::Renderable>(new gEngine::Renderable());
    block->setColor({1.0f, 1.0f, 1.0f, 0.5f});
    (block->getXform()).setPosition(53.0f, 30.0f);
    (block->getXform()).setSize(3.0f, 3.0f);
    (block->getXform()).setRotationInRad(2.8f);
    
    p1 = std::shared_ptr<gEngine::Renderable>(new gEngine::Renderable());
    p1->setColor({1.0f, 0.0f, 0.0f, 1.0f});
    (p1->getXform()).setSize(0.2f, 0.2f);
    p2 = std::shared_ptr<gEngine::Renderable>(new gEngine::Renderable());
    p2->setColor({0.0f, 1.0f, 0.0f, 1.0f});
    (p2->getXform()).setSize(0.2f, 0.2f);
    p3 = std::shared_ptr<gEngine::Renderable>(new gEngine::Renderable());
    p3->setColor({1.0f, 0.0f, 1.0f, 1.0f});
    (p3->getXform()).setSize(0.2f, 0.2f);
    p4 = std::shared_ptr<gEngine::Renderable>(new gEngine::Renderable());
    p4->setColor({0.0f, 0.0f, 1.0f, 1.0f});
    (p4->getXform()).setSize(0.2f, 0.2f);
    box =std::shared_ptr<gEngine::BoundingBox>(new gEngine::BoundingBox());
    blockBox = std::shared_ptr<gEngine::BoundingBox>(new gEngine::BoundingBox());
    mHit = std::shared_ptr<gEngine::SpriteAnimateRenderable>(new gEngine::SpriteAnimateRenderable(kHit));
    mHit->setColor({1.0f, 1.0f, 1.0f, 0.0f});
    (mHit->getXform()).setPosition(50.0f, 30.0f);
    (mHit->getXform()).setSize(1.0f, 1.0f);
    mHit->setSpriteSequence(512, 0, 32, 32, 4, 0);
    mHit->setAnimationType(gEngine::SpriteAnimateRenderable::ANIMATE_SWING);
    mHit->setAnimationInterval(10);
    
  
    gameObj = std::shared_ptr<gEngine::GameObject>(new gEngine::GameObject(mHit));
}
void MyGame::update()
{
    mHit->updateAnimation();
    GLfloat delta = 0.05f;
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_W))
    {
        gameObj->translate(glm::vec2(0.0f, delta), gEngine::GameObject::SELF_SPACE);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_S))
    {
        gameObj->translate(glm::vec2(0.0f, -delta), gEngine::GameObject::SELF_SPACE);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_A))
    {
        gameObj->rotateInRad(delta);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_D))
    {
        gameObj->rotateInRad(-delta);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_I))
    {
        glm::vec2 v = box->getSizeScale();
        v[1] += delta;
        box->setSizeScale(v);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_K))
    {
        glm::vec2 v = box->getSizeScale();
        v[1] -= delta;
        box->setSizeScale(v);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_J))
    {
        glm::vec2 v = box->getSizeScale();
        v[0] -= delta;
        box->setSizeScale(v);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_L))
    {
        glm::vec2 v = box->getSizeScale();
        v[0] += delta;
        box->setSizeScale(v);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_T))
    {
        glm::vec2 v = box->getOffset();
        v[1] +=delta;
        box->setOffset(v);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_G))
    {
        glm::vec2 v = box->getOffset();
        v[1] -=delta;
        box->setOffset(v);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_F))
    {
        glm::vec2 v = box->getOffset();
        v[0] -=delta;
        box->setOffset(v);
    }
    if((gEngine::Input::getInstance())->isKeyPressed(KEY_H))
    {
        glm::vec2 v = box->getOffset();
        v[0] +=delta;
        box->setOffset(v);
    }
    std::vector<glm::vec2> vec = box->getBoxVertex(mHit->getXform());
    GLfloat x = vec[0][0];
    GLfloat y = vec[0][1];
    (p1->getXform()).setPosition(x, y);
    (p2->getXform()).setPosition(vec[1][0], vec[1][1]);
    (p3->getXform()).setPosition(vec[2][0], vec[2][1]);
    (p4->getXform()).setPosition(vec[3][0], vec[3][1]);
    gEngine::OBB obb1(box->getBoxVertex(mHit->getXform()));
    gEngine::OBB obb2(blockBox->getBoxVertex(block->getXform()));
    if(obb1.isCollidWithOBB(&obb2))
    {
        gameObj->setVisibility(false);
    }
    else
    {
        gameObj->setVisibility(true);
    }
    mCamera->setWCCenter((mHit->getXform()).getXPos(), (mHit->getXform()).getYPos());
    
}
void MyGame::draw()
{
    //A: clear the canvas
    (gEngine::Core::getInstance())->clearCanvas({0.9, 0.9, 0.9, 1.0});
    //B: Activate the drawing Camera
    mCamera->setupViewProjection();
  
    gameObj->draw(mCamera);
    p1->draw(mCamera);
    p2->draw(mCamera);
    p3->draw(mCamera);
    p4->draw(mCamera);
    block->draw(mCamera);
    
}

/*void MyGame::initText(std::shared_ptr<gEngine::FontRenderable> font, GLfloat posX, GLfloat posY, std::vector<GLfloat> color, GLfloat textH)
{
    font->setColor(color);
    (font->getXform()).setPosition(posX, posY);
    font->setTextHeight(textH);
}*/
