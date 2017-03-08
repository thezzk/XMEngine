//
//  ResourceMap.cpp
//  XMEngine
//
//  Created by thezzk on 17/2/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "ResourceMap.h"
#include "assert.h"

namespace gEngine {

    void ResourceMap::setLoadCompleteCallback(CallbackFuncType funct)
    {
        mLoadCompleteCallback = funct;
        checkForAllLoadComplete();
    }
    
    void ResourceMap::asyncLoadRequest(std::string rName)
    {
        mResourceMap[rName] =std::shared_ptr<Asset>(new Asset());  //hold for the resource to be loaded
        ++mNumOutstandingLoads;
    }
    
    void ResourceMap::asyncLoadCompleted(std::string rName, std::shared_ptr<Asset> loadedAsset)
    {
        if(isAssetLoaded(rName))
        {//Do Nothing!
        }
        else
        {
            std::cout<<"gEngine::ResourceMap.asyncLoadComplete: ["<<rName<<"] not in map!"<<std::endl;
        }
        mResourceMap[rName] = loadedAsset;
        --mNumOutstandingLoads;
        checkForAllLoadComplete();

    }
    
    bool ResourceMap::isAssetLoaded(std::string rName)
    {
        if(mResourceMap.find(rName) == mResourceMap.end())
        {
            return false;
        }
        return true;
    }
    
    void ResourceMap::checkForAllLoadComplete()
    {
        if((mNumOutstandingLoads == 0) && (mLoadCompleteCallback != NULL))
        {
            // ensures the load complete and the callback has been set correctly
            CallbackFuncType funToCall = mLoadCompleteCallback;
            mLoadCompleteCallback = NULL;
            funToCall();
        }
    }
    
    
    void ResourceMap::unloadAsset(std::string rName)
    {
        if(mResourceMap.find(rName) != mResourceMap.end())
        {
            mResourceMap.erase(mResourceMap.find(rName));
        }
    }
    
    
    
}



