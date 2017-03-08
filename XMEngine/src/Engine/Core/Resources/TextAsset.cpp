//
//  TextAsset.cpp
//  XMEngine
//
//  Created by thezzk on 17/2/25.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "TextAsset.h"

namespace gEngine{
    
    TextAsset::TextAsset(): textContent("")
    {
    }
    
    TextAsset::TextAsset(std::string text): textContent(text)
    {
    }
    
    TextAsset::~TextAsset()
    {
    }
    
    std::string TextAsset::getTextContent()
    {
        return textContent;
    }
    
    void TextAsset::setTextContent(std::string text)
    {
        textContent = text;
    }
    
} //namespace gEnginew