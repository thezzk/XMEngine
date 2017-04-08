//
//  DefaultResources.cpp
//  XMEngine
//
//  Created by thezzk on 17/3/2.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "DefaultResources.h"
#include "TextFileLoader.h"

namespace gEngine{

    
    std::shared_ptr<SimpleShader> DefaultResources::getConstColorShader()
    {
        return mConstColorShader;
    }
    std::shared_ptr<TextureShader> DefaultResources::getTextureShader()
    {
        return mTextureShader;
    }
    std::shared_ptr<SpriteShader> DefaultResources::getSpriteShader()
    {
        return mSpriteShader;
    }
    
    void DefaultResources::createShaders()
    {
        mConstColorShader = std::shared_ptr<SimpleShader>(new SimpleShader(kSimpleVS, kSimpleFS));
        mTextureShader = std::shared_ptr<TextureShader>(new TextureShader(kTextureVS, kTextureFS));
        mSpriteShader = std::shared_ptr<SpriteShader>(new SpriteShader(kTextureVS, kTextureFS));
    }
    
    void DefaultResources::initialize()
    {
        printf("initilize\n");
        // constant color shader
        (TextFileLoader::getInstance())->loadTextFile(kSimpleVS, TextFileLoader::E_TEXT_FILE);
        (TextFileLoader::getInstance())->loadTextFile(kSimpleFS, TextFileLoader::E_TEXT_FILE);
        // texture shader
        (TextFileLoader::getInstance())->loadTextFile(kTextureVS, TextFileLoader::E_TEXT_FILE);
        (TextFileLoader::getInstance())->loadTextFile(kTextureFS, TextFileLoader::E_TEXT_FILE);
        
        (ResourceMap::getInstance())->setLoadCompleteCallback(LoadCompleteCallback);
        
    }
    
    
    
    
} //namespace gEngine