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

class MyGame: public gEngine::Scene
{
private:
    std::shared_ptr<gEngine::Camera> mCamera;
    std::vector<std::shared_ptr<gEngine::Renderable>> mSqSet;
public:
    std::string kSceneFile = "assets/scene.xml";
    virtual void loadScene();
    virtual void unloadScene();
    virtual void initialize();
    virtual void update();
    virtual void draw();
    MyGame();
    virtual ~MyGame();
    
};
#endif /* MyGame_hpp */
