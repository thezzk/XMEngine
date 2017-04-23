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
#include "FontRenderable.h"
#include "GameObjects.h"
#include "BoundingBox.h"
class MyGame: public gEngine::Scene
{
private:
    std::shared_ptr<gEngine::GameObject> gameObj;
    std::shared_ptr<gEngine::Camera> mCamera;
    std::shared_ptr<gEngine::BoundingBox> box;
    std::shared_ptr<gEngine::BoundingBox> blockBox;
    std::shared_ptr<gEngine::SpriteAnimateRenderable> mHit;
    std::shared_ptr<gEngine::Renderable> p1;
    std::shared_ptr<gEngine::Renderable> p2;
    std::shared_ptr<gEngine::Renderable> p3;
    std::shared_ptr<gEngine::Renderable> p4;
    std::shared_ptr<gEngine::Renderable> block;
    
    void initText(std::shared_ptr<gEngine::FontRenderable> font, GLfloat posX, GLfloat posY, std::vector<GLfloat> color, GLfloat textH);
public:
   
    std::string kBgClip = "assets/sounds/BGClip.wav";
    std::string kCue = "assets/sounds/MyGame_cue.wav";
    std::string kMinionSprite = "assets/minion_sprite.tga";
    std::string kActor = "assets/Actor.tga";
    std::string kMountain = "assets/Mountains1.tga";
    std::string kFontImage = "assets/Consolas-72.tga";
    std::string kHit = "assets/spritesheet.tga";
    
    std::string kFontCon16 = "assets/fonts/Consolas-16";
    std::string kFontCon24 = "assets/fonts/Consolas-24";
    std::string kFontCon32 = "assets/fonts/Consolas-32";
    std::string kFontCon72 = "assets/fonts/Consolas-72";
    std::string kFontSeg96 = "assets/fonts/Segment7-96";
    
    virtual void loadScene();
    virtual void unloadScene();
    virtual void initialize();
    virtual void update();
    virtual void draw();
    MyGame();
    virtual ~MyGame();
    
};
#endif /* MyGame_hpp */
