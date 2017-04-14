//
//  AudioClips.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef AudioClips_hpp
#define AudioClips_hpp

#include <iostream>
#include "SFML/Audio.hpp"

#include "SingletonBase.h"
#include "SoundAsset.h"
#include "ResourceMap.h"

namespace gEngine{
    
class AudioClips:public SingletonBase<AudioClips>
{
public:
    friend SingletonBase<AudioClips>;
    void loadAudio(std::string clipName);
    void unloadAudio(std::string clipName);
    void playACue(std::string clipName);
    void playBackgroundAudio(std::string clipName);
    void stopBackgroundAudio();
    bool isBackgroundAudioPlaying();
private:
    //Singleton pattern support
    AudioClips():bgmAudio(NULL){};
    AudioClips(const AudioClips&){};
    AudioClips &operator=(const AudioClips&);
    
    
    std::shared_ptr<SoundAssets> bgmAudio;
    void loadAudioTask(std::string clipName)
    {
        std::shared_ptr<Asset> soundContent(new SoundAssets(clipName));
        (ResourceMap::getInstance())->asyncLoadCompleted(clipName, soundContent);
    }
};
    
}// namespace gEngine

#endif /* AudioClips_hpp */
