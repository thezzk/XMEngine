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

class MyGame
{
private:
    std::shared_ptr<gEngine::Camera> mCamera;
    std::vector<std::shared_ptr<gEngine::Renderable>> mSqSet;
public:
    std::string kSceneFile = "assets/scene.xml";
    void loadScene();
    void unloadScene();
    void initialize();
    void update();
    void draw();
    MyGame();
    ~MyGame();
    
};
#endif /* MyGame_hpp */
