//
//  EngineCore.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/18.
//  Copyright © 2017年 thezzk. All rights reserved.
//
#include <cstdio>

#include "EngineCore.h"
#include "EngineVertexBuffer.h"
#include "EngineInput.h"
#include "DefaultResources.h"

namespace gEngine {

GLFWwindow* Core::getGLWindow()
{
    return window;
}

void Core::clearCanvas(std::vector<GLclampf> color)
{
    assert(color.size() >= 4);
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}

int Core::initializeGL()
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    
    
    // Open a window and create its OpenGL context
    window = glfwCreateWindow( 640, 480, "XMEngine", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    // Initialize GLEW
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    
    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    // Allows transperency with textures
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    
    return 0;
}

void Core::setCurrentScene(std::shared_ptr<Scene> scene)
{
    currentScene = scene;
}
    
std::shared_ptr<Scene> Core::getCurrentScene()
{
    return currentScene;
}
   
    
void Core::startScene(std::shared_ptr<Scene> scene)
{
    scene->loadScene();
    //scene.initialize();  call initialize only after sync load is done
    currentScene = scene;
    (GameLoop::getInstance())->start(currentScene);
}

int Core::initializeEngineCore(std::shared_ptr<Scene> scene)
{
    int retval = initializeGL();
    currentScene = scene;
    (VertexBuffer::getInstance())->initialize();
    (Input::getInstance())->initialize();
    (DefaultResources::getInstance())->initialize();
    return retval;
}

} // namespace gEngine