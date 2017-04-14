//
//  FontAsset.cpp
//  XMEngine
//
//  Created by thezzk on 17/4/11.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "FontAsset.h"

namespace  gEngine{
    FontAsset::FontAsset()
    {
        
    }
    
    FontAsset::FontAsset(std::shared_ptr<XMLAsset> fontInfo, std::shared_ptr<TextureAsset> textureInfo)
    {
        this->fontInfo = fontInfo;
        this->textureInfo = textureInfo;
    }
   
    FontAsset::~FontAsset()
    {
        
    }
    
    void FontAsset::setFontInfo(std::shared_ptr<XMLAsset> fontInfo)
    {
        this->fontInfo = fontInfo;
    }
    
    void FontAsset::setTextureInfo(std::shared_ptr<TextureAsset> textureInfo)
    {
        this->textureInfo = textureInfo;
    }
    
    const std::shared_ptr<XMLAsset> FontAsset::getFontInfo() const
    {
        return fontInfo;
    }
    
    const std::shared_ptr<TextureAsset> FontAsset::getTextureInfo() const
    {
        return textureInfo;
    }
}// namespace gEngine