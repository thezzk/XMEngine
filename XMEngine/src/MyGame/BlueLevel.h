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
#include "TextureRenderable.h"

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
    
    
private:
    std::string kSceneFile = "assets/BlueLevel.xml";
    std::string kBgClip = "assets/sounds/BGClip.wav";
    std::string kCue = "assets/sounds/BlueLevel_cue.wav";
    std::string kPortal = "assets/minion_portal.tga";
    std::string kCollector = "assets/minion_collector.tga";
    std::vector<std::shared_ptr<gEngine::Renderable>> mSqSet;
    std::shared_ptr<gEngine::Camera> mCamera;

    
};

#endif /* BlueLevel_hpp */
