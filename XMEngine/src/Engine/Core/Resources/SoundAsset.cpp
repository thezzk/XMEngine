//
//  SoundAsset.cpp
//  XMEngine
//
//  Created by thezzk on 17/3/22.
//  Copyright © 2017年 thezzk. All rights reserved.
//
#include "assert.h"

#include "SoundAsset.h"

namespace gEngine{
    
    SoundAssets::SoundAssets()
    {
        
    }
    
    SoundAssets::SoundAssets(std::string path)
    {
        assert(mSoundBuffer.loadFromFile(path));
        mSound.setBuffer(mSoundBuffer);
    }
    
    SoundAssets::~SoundAssets()
    {
        
    }
    
    void SoundAssets::setFileToBuffer(std::string filePath)
    {
        assert(mSoundBuffer.loadFromFile(filePath));
        mSound.setBuffer(mSoundBuffer);
    }
    
    sf::Sound& SoundAssets::getSound()
    {
        return mSound;
    }
    
}// namespace gEngine