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
    
    void DefaultResources::createShaders()
    {
        mConstColorShader = std::shared_ptr<SimpleShader>(new SimpleShader(kSimpleVS, kSimpleFS));
    }
    
    void DefaultResources::initialize()
    {
        printf("initilize\n");
        (TextFileLoader::getInstance())->loadTextFile(kSimpleVS, TextFileLoader::E_TEXT_FILE);
        (TextFileLoader::getInstance())->loadTextFile(kSimpleFS, TextFileLoader::E_TEXT_FILE);
        (ResourceMap::getInstance())->setLoadCompleteCallback(LoadCompleteCallback);
        
    }
    
    
    
    
} //namespace gEngine