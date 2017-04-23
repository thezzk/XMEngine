//
//  TextureRenderable.cpp
//  XMEngine
//
//  Created by thezzk on 17/3/25.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "TextureRenderable.h"
#include "EngineTexture.h"
#include "DefaultResources.h"


namespace gEngine {
    
    TextureRenderable::TextureRenderable(std::string mTexPath)
    {
        Renderable::setColor({1, 1, 1, 0});
        Renderable::setShader((DefaultResources::getInstance())->getTextureShader());
        this->mTexturePath = mTexPath;
    }
    
    TextureRenderable::~TextureRenderable()
    {
        
    }
    
    void TextureRenderable::draw(std::shared_ptr<const Camera> aCamera)
    {
        // activate the texture
        (Textures::getInstance())->activateTexture(mTexturePath);
        
        Renderable::draw(aCamera);
    }
    
    std::string TextureRenderable::getTexturePath()
    {
        return mTexturePath;
    }
    
    void TextureRenderable::setTexturePath(std::string path)
    {
        mTexturePath = path;
    }
    
}// namespace gEngine