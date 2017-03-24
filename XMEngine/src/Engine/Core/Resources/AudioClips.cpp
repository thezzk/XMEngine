//
//  AudioClips.cpp
//  XMEngine
//
//  Created by thezzk on 17/3/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//
#include "thread"

#include "AudioClips.h"
#include "ResourceMap.h"

namespace gEngine{
    
    void AudioClips::loadAudio(std::string clipName)
    {
        if(!((ResourceMap::getInstance())->isAssetLoaded(clipName)))
        {
            (ResourceMap::getInstance())->asyncLoadRequest(clipName);
            loadAudioTask(clipName);

        }
        else
        {
            (ResourceMap::getInstance())->incAssetRefCount(clipName);
        }
    }
    
    void AudioClips::unloadAudio(std::string clipName)
    {
        (ResourceMap::getInstance())->unloadAsset(clipName);
    }
    
    void AudioClips::playACue(std::string clipName)
    {
        std::shared_ptr<SoundAssets> clipAsset = (ResourceMap::getInstance())->retrieveAsset<SoundAssets>(clipName);
        
        if(clipAsset != NULL)
        {
            (clipAsset->getSound()).play();
        }
    }
    
    void AudioClips::playBackgroundAudio(std::string clipName)
    {
        std::shared_ptr<SoundAssets> clipAsset = (ResourceMap::getInstance())->retrieveAsset<SoundAssets>(clipName);
        
        if(clipAsset != NULL)
        {
            stopBackgroundAudio();
            bgmAudio = clipAsset;
            (clipAsset->getSound()).setLoop(true);
            (clipAsset->getSound()).play();
        }

    }
    
    void AudioClips::stopBackgroundAudio()
    {
        if(bgmAudio != NULL)
        {
            (bgmAudio->getSound()).stop();
            bgmAudio = NULL;
        }
    }
    
    bool AudioClips::isBackgroundAudioPlaying()
    {
        return (bgmAudio != NULL);
    }
}// namespce gEngine