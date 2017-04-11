//
//  MyGame.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef MyGame_hpp
#define MyGame_hpp

#include "iostream"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "SimpleShader.h"
#include "Renderable.h"
#include "Camera.h"
#include "Scene.h"
#include "SpriteRenderable.h"
#include "SpriteAnimateRenderable.h"

class MyGame: public gEngine::Scene
{
private:
    std::shared_ptr<gEngine::Camera> mCamera;
    std::shared_ptr<gEngine::SpriteAnimateRenderable> mRightMinion;
    std::shared_ptr<gEngine::SpriteAnimateRenderable> mLeftMinion;
    
 public:
   
    std::string kBgClip = "assets/sounds/BGClip.wav";
    std::string kCue = "assets/sounds/MyGame_cue.wav";
    //std::string kPortal = "assets/minion_portal.tga";
    //std::string kCollector = "assets/minion_collector.tga";
    std::string kMinionSprite = "assets/minion_sprite.tga";
    std::string kFontImage = "assets/Consolas-72.tga";
    
    virtual void loadScene();
    virtual void unloadScene();
    virtual void initialize();
    virtual void update();
    virtual void draw();
    MyGame();
    virtual ~MyGame();
    
};
#endif /* MyGame_hpp */
