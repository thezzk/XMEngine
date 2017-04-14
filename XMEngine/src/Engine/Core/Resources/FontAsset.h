//
//  FontAsset.hpp
//  XMEngine
//
//  Created by thezzk on 17/4/11.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef FontAsset_hpp
#define FontAsset_hpp

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Asset.h"
#include "XMLAsset.h"
#include "TextureAsset.h"

namespace gEngine{
    
class FontAsset: public Asset
{
public:
  
    FontAsset();
    FontAsset(std::shared_ptr<XMLAsset> fontInfo, std::shared_ptr<TextureAsset> textureInfo);
    virtual ~FontAsset();
    void setFontInfo(std::shared_ptr<XMLAsset> fontInfo);
    void setTextureInfo(std::shared_ptr<TextureAsset> textureInfo);
    const std::shared_ptr<XMLAsset> getFontInfo() const;
    const std::shared_ptr<TextureAsset> getTextureInfo() const;
    
    
private:
    std::shared_ptr<XMLAsset> fontInfo;
    std::shared_ptr<TextureAsset> textureInfo;
    
};
}// namespace gEngine

#endif /* FontAsset_hpp */
