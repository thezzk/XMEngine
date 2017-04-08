//
//  TextureAsset.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/26.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef TextureAsset_hpp
#define TextureAsset_hpp

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Asset.h"

namespace gEngine{
    
class TextureAsset: public Asset
{
public:
    typedef struct
    {
        GLubyte *imageData;
        GLuint bpp;//pixel depth
        GLuint width;
        GLuint height;
        GLuint texID;
    }TextureInfo;
    TextureAsset();
    TextureAsset(TextureInfo info);
    virtual ~TextureAsset();
    void setTextureInfo(TextureInfo info);
    const TextureInfo& getTextureInfo() const;
private:
    TextureInfo textureInfo;
    
};

}// namespace gEngine

#endif /* TextureAsset_hpp */
