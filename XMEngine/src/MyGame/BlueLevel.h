//
//  BlueLevel.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/19.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef BlueLevel_hpp
#define BlueLevel_hpp

#include <iostream>
#include "vector"

#include "Scene.h"
#include "Camera.h"
#include "Renderable.h"

class BlueLevel:public gEngine::Scene
{
public:
    BlueLevel();
    virtual ~BlueLevel();
    virtual void initialize();
    virtual void loadScene();
    virtual void unloadScene();
    virtual void update();
    virtual void draw();
    std::shared_ptr<gEngine::Camera> mCamera;
    std::vector<std::shared_ptr<gEngine::Renderable>> mSqSet;
    
private:
    std::string kSceneFile = "assets/BlueLevel.xml";
    
};

#endif /* BlueLevel_hpp */
