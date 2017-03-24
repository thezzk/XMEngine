//
//  SoundAsset.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/22.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef SoundAsset_hpp
#define SoundAsset_hpp

#include "iostream"
#include "SFML/Audio.hpp"

#include "Asset.h"


namespace gEngine {
    
class SoundAssets:public Asset
{
public:
    SoundAssets();
    SoundAssets(std::string path);
    virtual ~SoundAssets();
    void setFileToBuffer(std::string filePath);
    sf::Sound& getSound();
private:
    sf::Sound mSound;
    sf::SoundBuffer mSoundBuffer;
    
};
    
}// namespace gEngine

#endif /* SoundAsset_hpp */
