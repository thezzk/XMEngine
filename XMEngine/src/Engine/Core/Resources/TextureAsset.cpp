//
//  TextureAsset.cpp
//  XMEngine
//
//  Created by thezzk on 17/3/26.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "TextureAsset.h"

namespace gEngine{

    TextureAsset::TextureAsset()
    {
        
    }
    
    TextureAsset::TextureAsset(TextureAsset::TextureInfo info)
    {
        textureInfo = info;
    }
    
    TextureAsset::~TextureAsset()
    {
        
    }
    
    void TextureAsset::setTextureInfo(TextureInfo info)
    {
        textureInfo = info;
    }
    
    const TextureAsset::TextureInfo& TextureAsset::getTextureInfo() const
    {
        return textureInfo;
    }

}// namespace gEngine