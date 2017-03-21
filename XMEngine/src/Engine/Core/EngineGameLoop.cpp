//
//  EngineGameLoop.cpp
//  XMEngine
//
//  Created by thezzk on 17/1/29.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "EngineGameLoop.h"
#include "EngineCore.h"
#include "TimeUtil.h"
#include "EngineInput.h"
#include "EngineCore.h"


namespace gEngine {
void GameLoop::runLoop()
{
    
    while(mIsLoopRunning)   //A: the loop itself
    {
        //B: compute elapsed time since last RunLoop was executed
        mCurrentTime = (TimeUtil::getInstance())->getMillisecond();
        mElapsedTime = mCurrentTime - mPreviousTime;
        mPreviousTime = mCurrentTime;
        mLagTime += mElapsedTime;
        
        //C: update the game the appropriate number of times
        //  Update only every Milliseconds per frame
        //  If lag larger the update frames, update until caught up
        while((mLagTime >= kMPF) && mIsLoopRunning)
        {
            (Input::getInstance())->update();
            myGame->update();
            mLagTime -= kMPF;
        }
        
        //D: draw
        myGame->draw();
        GLFWwindow* window = (Core::getInstance())->getGLWindow();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    if(mIsLoopRunning == false)
    {
        // when loop stop unload the scene
        myGame->unloadScene();
    }
}

void GameLoop::start(std::shared_ptr<Scene> myGame)
{
    this->myGame = myGame;
    (ResourceMap::getInstance())->setLoadCompleteCallback(loadSceneCompleteCallback);
}

void GameLoop::loadSceneCompleteCallback()
{
    
    (GameLoop::getInstance())->myGame->initialize();
    (GameLoop::getInstance())->startLoop();
}
    
void GameLoop::startLoop()
{
    //A: reset time
    mPreviousTime = (TimeUtil::getInstance())->getMillisecond();
    mLagTime = 0;
    //B: remember that loop is now running
    mIsLoopRunning = true;
    
    //C: start the loop
    runLoop();
 
}
    
void GameLoop::stop()
{
    mIsLoopRunning = false;
}
    
}// namespace gEngine
