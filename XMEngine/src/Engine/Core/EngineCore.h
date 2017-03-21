//
//  EngineCore.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/18.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef EngineCore_hpp
#define EngineCore_hpp
#include <cstdio>
#include <cstdlib>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "SingletonBase.h"
#include "MyGame.h"
#include "EngineGameLoop.h"
namespace gEngine {
class Core: public SingletonBase<Core>
{
    
public:
    friend SingletonBase<Core>;
    
    int initializeEngineCore(std::shared_ptr<Scene> scene);
    void clearCanvas(std::vector<GLclampf> color);
    GLFWwindow* getGLWindow();
    std::shared_ptr<Scene> getCurrentScene();
    void setCurrentScene(std::shared_ptr<Scene> scene);
    void startScene(std::shared_ptr<Scene> scene);
private:
    Core(){}
    Core(const Core&){}
    Core &operator=(const Core&);
    GLFWwindow* window;
    std::shared_ptr<Scene> currentScene;
    
    int initializeGL();
};

} //namespace gEngine
#endif /* EngineCore_hpp */
