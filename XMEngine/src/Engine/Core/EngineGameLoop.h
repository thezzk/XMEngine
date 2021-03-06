//
//  EngineGameLoop.hpp
//  XMEngine
//
//  Created by thezzk on 17/1/29.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef EngineGameLoop_hpp
#define EngineGameLoop_hpp

#include "iostream"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


#include "SingletonBase.h"
#include "MyGame.h"
#include "ResourceMap.h"

namespace gEngine
{
    
class GameLoop:public SingletonBase<GameLoop>
{
public:
    friend SingletonBase<GameLoop>;
    
    const int kFPS = 60; // Frames per second
    const int kMPF = 1000 / kFPS;  // Milleseconds per frame
    
    void start(std::shared_ptr<Scene> myGame);
    void stop();
    
private:
    /*Singleton pattern support*/
    GameLoop(){}
    GameLoop(const GameLoop&){}
    GameLoop &operator=(const GameLoop&);
    /*-------------------------*/

    // Variables for timing gameloop
    unsigned long mPreviousTime;
    unsigned long mLagTime;
    unsigned long mCurrentTime;
    unsigned long mElapsedTime;
    
    // The current loop state (running or should stop)
    bool mIsLoopRunning = false;
    
    // Reference to game logic
    std::shared_ptr<Scene> myGame;
    
    void runLoop();
    void startLoop();
    static void loadSceneCompleteCallback();
    
};
    
}// namespace gEngine

#endif /* EngineGameLoop_hpp */
