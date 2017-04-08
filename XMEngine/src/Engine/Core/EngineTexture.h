//
//  EngineTexture.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/26.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef EngineTexture_hpp
#define EngineTexture_hpp

#include <iostream>

#include "SingletonBase.h"
#include "TextureAsset.h"

namespace gEngine {
class Textures:public SingletonBase<Textures>
{
public:
    friend SingletonBase<Textures>;
    void loadTexture(std::string textureName);
    void unloadTexture(std::string textureName);
    void activateTexture(std::string textureName);
    void deactivateTexture(std::string textureName);
    TextureAsset::TextureInfo getTextureInfo(std::string textureName);
private:
    //Singleton pattern support
    Textures(){}
    Textures(const Textures&){}
    Textures &operator=(const Textures&);
    

    bool loadTGA(TextureAsset::TextureInfo& texture, const char* fileName);
};
}// namespace gEngine

#endif /* EngineTexture_hpp */
