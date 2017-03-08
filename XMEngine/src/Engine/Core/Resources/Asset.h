//
//  Asset.hpp
//  XMEngine
//
//  Created by thezzk on 17/2/21.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef Asset_hpp
#define Asset_hpp

#include "iostream"

namespace gEngine{
    
class Asset
{
public:
    enum AssetType
    {
        NONE = 0,
        TEXT = 1
    };
    virtual ~Asset();
};
    
} //namespace gEngine

#endif /* Asset_hpp */
