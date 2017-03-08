//
//  ResourceMap.hpp
//  XMEngine
//
//  Created by thezzk on 17/2/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef ResourceMap_hpp
#define ResourceMap_hpp

#include "iostream"
#include <map>

#include "SingletonBase.h"
#include "Asset.h"
#include "TextAsset.h"
namespace gEngine {


    
class ResourceMap: public SingletonBase<ResourceMap>
{
    typedef void (*CallbackFuncType)();
public:
    friend SingletonBase<ResourceMap>;
    
    void setLoadCompleteCallback(CallbackFuncType funct);
    void asyncLoadRequest(std::string rName);
    void asyncLoadCompleted(std::string rName, std::shared_ptr<Asset> loadedAsset);
    bool isAssetLoaded(std::string rName);
    void unloadAsset(std::string rName);
    
    template<typename T>
    std::shared_ptr<T> retrieveAsset(std::string rName)
    {
        assert(dynamic_cast<T*>(mResourceMap[rName].get()) != NULL);
        std::shared_ptr<T> derivedAsset = std::dynamic_pointer_cast<T>(mResourceMap[rName]);
        return derivedAsset;
    }

private:
    //Singleton pattern support
    ResourceMap(): mNumOutstandingLoads(0), mLoadCompleteCallback(NULL){}
    ResourceMap(const ResourceMap&){}
    ResourceMap &operator=(const ResourceMap&);
    //Member var
    std::map<std::string, std::shared_ptr<Asset>> mResourceMap;
    int mNumOutstandingLoads;
    CallbackFuncType mLoadCompleteCallback;
    //Member function
    void checkForAllLoadComplete();
    
};
    
} //namespace gEngine

#endif /* ResourceMap_hpp */
