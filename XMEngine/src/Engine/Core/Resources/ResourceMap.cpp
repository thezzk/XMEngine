//
//  ResourceMap.cpp
//  XMEngine
//
//  Created by thezzk on 17/2/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#include "ResourceMap.h"
#include "assert.h"
#include "mutex"

namespace gEngine {

    void ResourceMap::setLoadCompleteCallback(CallbackFuncType funct)
    {
        mLoadCompleteCallback = funct;
        while(!checkForAllLoadComplete()){};
        //Wait for all async load complete
    }
    
    void ResourceMap::asyncLoadRequest(std::string rName)
    {
        mResourceMap[rName] =std::shared_ptr<Asset>(new Asset());  //hold for the resource to be loaded
        ++mNumOutstandingLoads;
    }
    
    void ResourceMap::asyncLoadCompleted(std::string rName, std::shared_ptr<Asset> loadedAsset)
    {
        std::lock_guard<std::mutex> mux(loadCompleteMutex);
        if(isAssetLoaded(rName))
        {//Do Nothing!
        }
        else
        {
            std::cout<<"gEngine::ResourceMap.asyncLoadComplete: ["<<rName<<"] not in map!"<<std::endl;
        }
        mResourceMap[rName] = loadedAsset;
        --mNumOutstandingLoads;
    }
    
    bool ResourceMap::isAssetLoaded(std::string rName)
    {
        if(mResourceMap.find(rName) == mResourceMap.end())
        {
            return false;
        }
        return true;
    }
    
    bool ResourceMap::checkForAllLoadComplete()
    {
        if((mNumOutstandingLoads == 0) && (mLoadCompleteCallback != NULL))
        {
            // ensures the load complete and the callback has been set correctly
            CallbackFuncType funToCall = mLoadCompleteCallback;
            mLoadCompleteCallback = NULL;
            funToCall();
            return true;
        }
        return false;
    }
    
    
    int ResourceMap::unloadAsset(std::string rName)
    {
        int count = 0;
        if(mResourceMap.find(rName) != mResourceMap.end())
        {
            mResourceMap[rName]->refCount -= 1;
            count = mResourceMap[rName]->refCount;
            if(count == 0)
            {
                mResourceMap.erase(mResourceMap.find(rName));
            }
        }
        return count;
    }
    
    void ResourceMap::incAssetRefCount(std::string rName)
    {
        mResourceMap[rName]->refCount += 1;
    }
    
}



