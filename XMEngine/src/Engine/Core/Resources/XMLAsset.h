//
//  XMLAsset.hpp
//  XMEngine
//
//  Created by thezzk on 17/3/10.
//  Copyright © 2017年 thezzk. All rights reserved.
//

#ifndef XMLAsset_hpp
#define XMLAsset_hpp

#include "Asset.h"
#include "tinyxml2.h"

namespace gEngine{
    
class XMLAsset:public Asset
{
public:
    XMLAsset();
    XMLAsset(std::string xmlText);
    virtual ~XMLAsset();
    int setXMLDoc(std::string xmlStr);
    const tinyxml2::XMLDocument& getXMLDoc();
private:
    tinyxml2::XMLDocument xmlDoc;
    
};
    
} //namespace gEngine

#endif /* XMLAsset_hpp */
