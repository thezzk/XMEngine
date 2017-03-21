//
//  Scene.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/18.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <iostream>

namespace gEngine {

class Scene
{
public:
    virtual ~Scene(){};
    virtual void initialize() = 0;
    virtual void loadScene(){};
    virtual void unloadScene(){};
    virtual void update(){};
    virtual void draw(){};
    
};
    
} // namespace gEngine


#endif /* Scene_hpp */
