//
//  TextureRenderable.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/25.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef TextureRenderable_hpp
#define TextureRenderable_hpp

#include <iostream>

#include "Renderable.h"

namespace gEngine {
    
class TextureRenderable:public Renderable
{
public:
    TextureRenderable(std::string mTexturePath);
    virtual ~TextureRenderable();
    virtual void draw(glm::mat4 vpMatrix);
    std::string getTexturePath();
    void setTexturePath(std::string path);
private:
    std::string mTexturePath;
};
    
}// namespace gEngine

#endif /* TextureRenderable_hpp */
